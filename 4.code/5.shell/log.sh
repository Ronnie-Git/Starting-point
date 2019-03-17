#!/bin/bash

#记录用户登录登出信息

cat >> /etc/bash.bashrc << EOF
echo "`who am i`" >> mylog.log
EOF

cat >> /etc/.bash_logout << EOF
TIME=`who am i | awk '{printf $3" "$4}'`
USERMANE=`who am i | awk '{printf $1}'`
TIME=$[$(date +%s)-$(date +%s -d "$TIME")]
echo "$USERMANE 登录总时间：$[$TIME/60]分钟" >> mylog.log
EOF
