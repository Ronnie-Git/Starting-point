###  tftp https://www.linuxidc.com/Linux/2016-07/133255.htm

命令https://blog.csdn.net/lee244868149/article/details/39181029



**Ubuntu 16.04中安装tftp**

**1. 安装**

`apt-get install tftp-hpa tftpd-hpa`

 

**2. 建立目录**

`mkdir /tftpboot` # 这是建立tftp传输目录。

`sudo chmod 0777 /tftpboot`

`sudo touch test.txt` # test.txt文件最好输入内容以便区分

 

**3. 配置**

`vi /etc/default/tftpd-hpa`

TFTP_USERNAME="tftp"

TFTP_DIRECTORY="/tftpboot" # 这里是你的tftpd-hpa的服务目录,这个想建立在哪里都行

TFTP_ADDRESS="0.0.0.0:69"

TFTP_OPTIONS="-l -c -s" # 这里是选项,-c是可以上传文件的参数，-s是指定tftpd-hpa服务目录，上面已经指定

 

**4. 重启服务**

`sudo service tftpd-hpa restart` # 启动服务，这里要注意，采用的独立服务形式。

 

**5. 测试**

`cd /home`

`tftp localhost`  #localhost 表示本机

tftp>`get test.txt`  //test.txt 是之前在 /tftpboot 目录下新建的文件

tftp>`put test1.txt` //test1.txt 是在 /home 目录下新建的文件

tftp>`q`退出

**退出后，在/home目录下会有一个test.txt文件，在/tftpboot 目录下有test1.txt，表示tftp服务器安装成功！**



`cd 目录` 想要传过去的文件的所在路径

`tftp 对方IP` 连接

`put 文件名` 会传到对方 `/tftpboot 目录下`

`q` 退出

**退出后，在对方的`/tftpboot 目录下`会有你传的文件**





`cd 目录` 想要下载文件到的路径

`tftp 对方IP` 连接

`get 文件名` 会将对方 `/tftpboot 目录下`的文件下载到之前`cd`到的目录

`q` 退出

**退出后，在之前`cd`到的目录下会有你下载的文件**



### sftp

`sftp 远程主机名@远程ID`

**ssh tftp的结合体：可以使用`ls` `cd`等终端命令**



### 安装 LAMP

https://blog.csdn.net/trh0123/article/details/54645335

https://blog.csdn.net/pythonshell/article/details/52958075



**步骤一：安装apache **

`sudo apt install apache2` 

安装好后，在浏览器上输入你的ip，回车；即成功安装好apache了。



**步骤二：安装php7**  

`sudo apt install php7.0` 

输入版本信息，检测安装是否成功  

`php -v` 

PHP 7.0.4-7ubuntu2.1 (cli) ( NTS ) 

Copyright (c) 1997-2016 The PHP Group 

Zend Engine v3.0.0, Copyright (c) 1998-2016 Zend Technologies with Zend OPcache v7.0.6-dev, Copyright (c) 1999-2016, by Zend Technologies 

如果出现以上信息，则证明安装php7.0成功 整合一下php和apache    



安装apache2 php7 module  

`sudo apt-get install libapache2-mod-php7.0`

` sudo apt install libapache2-mod-php7.0`   



**步骤三：安装MySQL** 

`sudo apt-get install mysql-server mysql-client`  

然后整合一下php和mysql 

`sudo apt-get install php7.0-mysql`   



**登录mysql**

方法一：

`sudo cat /etc/mysql/debian.cnf`

`mysql -udebian-sys-maint -p`

输入密码



方法二：

`sudo mysql -uroot -p`



**步骤四：重启MySQL和Apache**  

`sudo service mysql restart` 

`sudo service apache2 restart`   



**步骤五：安装Phpmyadmin** 

`apt-get install phpmyadmin php-mbstring php-gettext`  



**步骤六：建立var/www/html/phpmyadmin软链接：   （http://你的IP/phpmyadmin/ 这样就能访问 会提示有错误The mbstring extension is missing.）**   



php配置文件php.ini：  

`vim /etc/php/7.0/apache2/php.ini`  

display_errors = On(显示错误日志）   

extension=php_mbstring.dll (开启mbstring)   



重启apache:  

`sudo /etc/init.d/apache2 restart` 

现在就完成了LAMP 从阿里云新系统到安装完结束



