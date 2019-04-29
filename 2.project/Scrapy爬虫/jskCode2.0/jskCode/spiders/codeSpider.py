# -*- coding: utf-8 -*-
import scrapy
import os
from scrapy import Request
from selenium import webdriver

class CodespiderSpider(scrapy.Spider):
    name = 'codeSpider'
    allowed_domains = ['jisuanke.com']
    start_url = 'https://www.jisuanke.com/course/786?view=study'
    cookie_file = "./cookie_file"
    path = "./data/"
    
    # 初始化网页起点、cookie等
    def __init__(self):
        driver = webdriver.Chrome()
        driver.set_page_load_timeout(10)
        driver.get("https://www.baidu.com")
        with open(self.cookie_file, "r") as fin:
            for line in fin:
                name, value, domain = line.strip().split("\t")
                cookie = {"name" : name, "value" : value, "domain" : domain}
                driver.add_cookie(cookie)
        self.driver = driver

    # 开始
    def start_requests(self):
        yield Request(url = self.start_url, callback = self.parse)

    # 获取代码链接和其文件名
    def parse(self, response):
        # 获取该课程每个模块的id
        li_list = response.xpath("//@data-chapter-id").extract()
        for li_item in li_list:
            # 获取该模块的名字 并以该名字建立文件夹
            dir_name_temp = "//li[@data-chapter-id='" + str(li_item) + "']/div[@class='chapter-section']/div[@class='chapter-title']/h2/text()"
            dir_name = self.path + response.xpath(dir_name_temp)[0].extract().encode("utf8")
            os.mkdir(dir_name) 
            
            # 获取编程题的链接 并将其题目名作为文件名
            href_list = []
            file_name = []
            a_list = response.xpath("//li[@data-chapter-id='" + str(li_item) + "']/ul[@class='jsk-list jsk-list-striped lessons']/li/a")
            for a_item in a_list:
                title = a_item.xpath("./span[@class='lesson-icon-challenge']")
                if len(title) == 0:
                    continue
                href_list.append(a_item.xpath("./@href")[0].extract())
                file_name_temp = a_item.xpath("./span[@class='lesson-title jsk-text-truncate']/text()")[0].extract()
                file_name.append(dir_name + "/" + file_name_temp.encode("utf8") + ".cpp")
            ind = 0
            for url in href_list:
                yield Request(url = "https:" + url, meta = {"file_name" : file_name[ind]}, callback = self.parse2)
                ind += 1
    
    # 判断哪一份代码是正确的并将其获取
    def parse2(self, response):
        tr_list = response.xpath("//div[@class='jsk-modal-bd']/table/tbody/tr")
        for tr in tr_list:
            tds = tr.xpath("./td[@class='jsk-text-success']")
            if len(tds) == 0:
                continue
            yield Request(url = tr.xpath(".//a/@href")[0].extract(), meta = response.meta, callback = self.save_code)
            break
   
    # 获取代码并将其保存在本地
    def save_code(self, response):
        file_name = response.meta["file_name"]
        code = response.xpath("//pre/text()")[0].extract()
        with open(file_name, "w") as fout:
            fout.write(code.encode("utf8"))
