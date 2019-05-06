#!/usr/bin/env python
# coding=utf-8

import poplib
import email

def get_userinfo():
    import json
    with open("userinfo.json", "r") as fin:
        return json.loads(fin.read())


mail = poplib.POP3("pop.163.com")
userinfo = get_userinfo()
mail.user(userinfo["username"])
mail.pass_(userinfo["password"])

stats = mail.stat()
msg = mail.retr(stats[0])
str = "\n".join(map(lambda i : i.decode(), msg[1]))
newmsg = email.message_from_string(str)
from email.header import decode_header
title = decode_header(newmsg["subject"])
from_user = decode_header(newmsg["from"])
to_user = decode_header(newmsg["to"])
print(from_user)
print(to_user)

#if len(title[0]) == 2:
#    title = title[0][0].decode(title[0][1])
#else :
#    title = title[0][0].decode()
print(title)

mail.close()
