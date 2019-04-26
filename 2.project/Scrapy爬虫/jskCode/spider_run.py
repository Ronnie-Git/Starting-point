#!/usr/bin/env python
# coding=utf-8

import os
# from scrapy import cmdline

# 运行爬取OJ上代码的爬虫
#cmdline.execute(["scrapy", "crawl", "codeSpider"])

# 运行爬取OJ上代码的爬虫
os.system("scrapy crawl codeSpider")

# 运行统计代码行数的脚本
os.system("bash code_line.sh")
