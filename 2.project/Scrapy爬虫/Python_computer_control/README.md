****

**正在维护当中。。。。。。**

------



## 爬虫项目

### 项目需求

**远程**



### 前期准备

通常不使用浏览器进行爬虫

1. pyenv
   - python 各版本不兼容，需要 pyenv 管理 python 环境，在各版本中切换
   - pyenv install 3.7.1
   - [安装pyenv](https://www.cnblogs.com/olajennings/p/8832481.html)
2. pycharm
   - python 的 IDE
   - 推荐上官网下载 [安装pycharm](https://blog.csdn.net/qq_38683692/article/details/79868391)
   - pycharm 新建的项目放在`PycharmProjects`文件夹中
   - 打开 pycharm 中的 Terminal: `View -> ToolWindows -> Terminal`
3. anaconda
   - [官网下载](https://www.anaconda.com/distribution/)
   - [安装anaconda](https://www.jianshu.com/p/3e53407f8bd4)
   - [anaconda换源](https://blog.csdn.net/dream_allday/article/details/80344511)
   - 切换环境等常用命令
     - `conda activate 环境名`  进入某环境
     - `conda deactivate` 退出环境
     - `conda env list` 列举当前所有环境
     - `conda create -n your_env_name python=3.5` 创建指定python版本的环境
     - `conda remove -n your_env_name --all` 删除环境（不要乱删）
     - `activate your_env_name` 进入（激活）指定名字的环境
     - `conda install lib_name` 安装指定库名
     - `conda uninstall lib_name` 卸载指定库名
4. scrapy
   - [安装scrapy](https://blog.csdn.net/a6864657/article/details/82634187)
5. xpath
   - [scrapy框架xpath和css选择器语法](https://blog.csdn.net/mouday/article/details/80455560)

6. html
   * [html语法规则](https://www.cnblogs.com/wanglisong/p/6924886.html)



### 开发环境

- scrapy
- python3.7.3



## 软件说明 

### Scrapy 的使用

说明：爬虫框架

1. 下载器（Download）
2. 分析器（Parse）
3. 存储器（Store, Save, Date, Item(一项、条目)）



#### 1.新建爬虫项目

```
scrapy startproject [爬虫项目的名字]
```



#### 2.新建爬虫

```
cd 
scrapy genspider [爬虫的名字] [爬虫的域名]
```

使用 fake-useragent 模块随机生成 User-Agent

[Scrapy 设置随机 User-Agent](https://www.cnblogs.com/yuqiangli0616/p/9277263.html)



```python
url = 开始的网址
callback = 分析的方法
```



#### 3.middlewares

```
from fake_useragent import UserAgent

class RandomUserAgentMiddleware(object):

    def __init__(self):
        self.agent = UserAgent()

    @classmethod
    def from_crawler(cls, crawler):
        return cls()

    def process_request(self, request, spider):
        request.headers.setdefault('User-Agent', self.agent.random)
```



#### 4.settings

**24 行左右**

```python
ROBOTSTXT_OBEY = False
```



#### 5.执行爬虫

```
scrapy crawl [爬虫名字](不加.py后缀)
```



## json

**是一种轻量级的数据交换格式。易于人阅读和编写。同时也易于机器解析和生成**

### JSON 语法规则

**在 JS 语言中，一切都是对象**。因此，任何支持的类型都可以通过 JSON 来表示，例如字符串、数字、对象、数组等。但是对象和数组是比较特殊且常用的两种类型：

- 对象表示为键值对
- 数据由逗号分隔
- 花括号保存对象
- 方括号保存数组



### 生成json格式

```python
#!/usr/bin/env python
# coding=utf-8

data = {
    "username" : ".......",
    "password" : "...." # 客户端授权密码 不是登录密码
}

import json
print(json.dumps(data))
```



### 使用json格式的数据

```python
#!/usr/bin/env python
# coding=utf-8

import json

with open("file", "r") as fin:
    data = json.loads(fin.read())
    print(data["username"])
    print(data["password"])
```



## 163邮箱

[Python 简单发送邮件 / 发送带各种附件邮件](https://blog.csdn.net/qq_20417499/article/details/80566265)

### 打开以下三个协议

* `POP3服务器: pop.163.com` 
  * 接收邮件的
  * 单向的，本地（客户端）做的修改，不会同步到服务器上，本地将邮件标记为已读，网页上不会标记为已读

* `SMTP服务器: smtp.163.com` 
  * 发送邮件 

* `IMAP服务器: imap.163.com` 
  * 类似接收邮件（双向的）



###  客户端授权密码

跟登录密码不是同一个，用 python 登录邮箱时使用的密码是客户端授权密码