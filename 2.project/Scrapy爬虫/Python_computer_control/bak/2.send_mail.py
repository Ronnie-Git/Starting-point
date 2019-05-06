#!/usr/bin/env python
# coding=utf-8

import smtplib
from email.mime.text import MIMEText


def get_userinfo():
    with open("userinfo.json", "r") as fin:
        import json
        return json.loads(fin.read())

# 发送表格邮件
def get_msg():
    return '''
    <table border="1">
        <thead>
        <tr>
            <td>id</td> <td>name</td> <td>age</td>
        </tr>
        </thead>
        <tbody>
        <tr>
            <td>1</td> <td>x</td> <td>456</td>
        </tr>
        </tbody>
    </table>
    '''

userinfo = get_userinfo()
mail = smtplib.SMTP("smtp.163.com")
mail.login(userinfo["username"], userinfo["password"])

msg = get_msg()
content = MIMEText(msg, _subtype = "html")
content["subject"] = "test title"
content["from"] = userinfo["username"]
content["to"] = userinfo["username"]


mail.sendmail(userinfo["username"], userinfo["username"], content.as_string())

mail.close()
