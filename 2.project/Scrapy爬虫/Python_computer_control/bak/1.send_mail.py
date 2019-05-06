#!/usr/bin/env python
# coding=utf-8

# 发送邮件

import smtplib
from email.mime.text import MIMEText


def get_userinfo():
    with open("userinfo.json", "r") as fin:
        import json
        return json.loads(fin.read())

def get_msg():
    return "test email"

userinfo = get_userinfo()
mail = smtplib.SMTP("smtp.163.com")
mail.login(userinfo["username"], userinfo["password"])

msg = get_msg()
content = MIMEText(msg)
content["subject"] = "test title"
content["from"] = userinfo["username"]
content["to"] = userinfo["username"]


mail.sendmail(userinfo["username"], userinfo["username"], content.as_string())

mail.close()
