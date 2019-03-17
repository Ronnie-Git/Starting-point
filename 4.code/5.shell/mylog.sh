#!/bin/bash

#记录用户登录登出时间

TIME=`who am i | awk '{printf $3" "$4}'`
USERMANE=`who am i | awk '{printf $1}'`
IP=`who am i | awk '{printf $5}'`
G=`who am i | awk '{printf $2}'`
echo "$TIME $USERMANE login $G $IP" >> mylog.log

TIME=$[$(date +%s)-$(date +%s -d "$TIME")]
TIME1=`date +"%Y-%m-%d %H:%M"`
echo "$TIME1 $USERMANE logout $[$TIME/60]分钟" >> mylog.log
