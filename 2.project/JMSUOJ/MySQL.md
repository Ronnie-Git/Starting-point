### 参考博客和文档

* https://blog.csdn.net/chenqianfang/article/details/79958518
* https://www.runoob.com/mysql/mysql-tutorial.html
* https://blog.csdn.net/fuqiuai/article/details/79495807



## 一. 安装MySQL

#### 1.安装前先更新软件包列表：

```shell
$ sudo apt update
```

#### 2.在Ubuntu 16.04上安装MySQL：

```shell
$ sudo apt-get install mysql-server mysql-client
```

#### 3.在安装过程中需要你输入MySQL 管理员用户(root)密码，如下图：

![输入root用户密码](https://img-blog.csdn.net/20160826164029078)

#### 4.运行MySQL初始化安全脚本：

```shell
$ sudo mysql_secure_installation
```

#### 5.根据提示信息设置：

![根据提示信息设置](https://img-blog.csdn.net/20160826170229534)

> mysql_secure_installation脚本设置的东西：更改root密码、移除MySQL的匿名用户、禁止root远程登录、删除test数据库。使用上面的这些选项可以提高MySQL的安全。



## 二. MySQL数据库基本使用

#### 1.使用root用户登录：

```shell
$ mysql -u root -p
```

#### 2.输入root密码： 
![输入root密码](https://img-blog.csdn.net/20160826164847435)

#### 3.创建MySQL数据库和用户：

```shell
mysql> create database snailblog;
```

> 上面命令创建了一个名为snailblog的数据库。 

#### 4.创建用户，并使用snailblog数据库：

```shell
mysql> grant all on snailblog.* to 'man_user' identified by 'test1234';
```

![创建用户](https://img-blog.csdn.net/20160826165002905)

#### 5.使用新用户登录：

```shell
$ mysql -u man_user -p snailblog
```

![使用新用户登录](https://img-blog.csdn.net/20160826165044137)

#### 6.创建表：

```shell
mysql> CREATE TABLE user (id INT, name VARCHAR(20), email VARCHAR(20));
```

#### 7.插入记录：

```shell
mysql> INSERT INTO user (id,name,email) VALUES(1,"bar","bar@gmail.com");
mysql> INSERT INTO user (id,name,email) VALUES(2,"foo","foo@163.com");
mysql> INSERT INTO user (id,name,email) VALUES(3,"cat","cat@gmail.com");
```

#### 8.简单查询：

```shell
mysql> SELECT * FROM user;
```

![简单查询](https://img-blog.csdn.net/20160826165402859)

#### 9.退出MySQL命令行：

```shell
mysql> quit
Bye
```

#### 10.停止MySQL数据库服务：

```shell
$ sudo systemctl stop mysql.service
```

#### 11.启动MySQL数据库服务：

```shell
$ sudo systemctl start mysql.service
```

#### 12.重启MySQL数据库服务：

```shell
$ sudo systemctl restart mysql.service
```

#### 13.查看MySQL运行状态：

```shell
$ sudo systemctl status mysql.service
```

#### 14.MySQL的配置文件：

```shell
$ sudo vim /etc/mysql/mysql.conf.d/mysqld.cnf
```



## 三、基础使用教程

#### 1.安装mysql命令 ：

```shell
sudo apt-get install mysql-server mysql-client
```

#### 2.查看mysql的版本命令（注意-V是大写，不然会出现如下错误）：

```shell
mysql -V 
```

#### 3.启动mysql命令(关闭，重启等只需将start换成stop,restart等即可)：

```shell
sudo service mysql start 
```

#### 4.登录mysql命令为：

```shell
mysql -u用户名 -p密码 
```

#### 5.连接远程数据库：

```shell
mysql -h <host> -P <port> -u<username> -p<password>
```



### 数据库操作
1.查看数据库：`> show databases;` （注意分号“；”不要落下） 
2.新建一个数据库命令：`> create database 数据库名称; `
   删除一个数据库命令：`> drop database 数据库名称; `
3.使用某个数据库：`> use 数据库名称;`



### 表操作

1.查看表命令：`> show tables;` 
2.建立一个新表：`> create table 表名 （字段参数）;` 或 `>create table if not exists 表名（字段参数）； `
   删除一个旧表：`> drop table 表名；` 或 `> drop table if exists 表名； `
3.查看表结构：`> desc 表名称;` 或 `> show columns from 表名称; `
4.对表数据的操作： 
   增：`> insert into 表名称 (字段名1，字段名2，字段名3......) values(字段名1的值，字段名2的值，字段名3的值......); `
   删：`> delete from 表名称 where 表达式;` 
   改：`> update 表名称 set 字段名=“新值” where 表达式；` 
   查：`> select 字段名1,字段名2,字段名3..... from 表名称;` 
5.增加字段：`> alter table 表名称 add 字段名 数据类型 其它;` (其它包括默认初始值的设定等等) 
6.删除字段：`> alter table 表名称 drop 字段名;`



### 用户相关操作

**注：以下命令均需先以root身份登录`mysql：mysql -uroot -p` **
1.添加新用户 
（1）创建新用户：`> insert into mysql.user(Host,User,Password) values("localhost","user1",password("password1")); `
（2）为用户分配权限： 
            设置用户可以在本地访问mysql：`grant all privileges on *.* to username@localhost identified by "password" ; `
            设置用户只能访问指定数据库：`grant all privileges on 数据库名.* to username@localhost identified by "password" ; `
（3）刷新系统权限表：`> flush privileges;` 
2.查看MySql当前所有的用户：`> SELECT DISTINCT User FROM mysql.user; `

3.删除用户及其数据字典中包含的数据：`> drop user 'xbb'@'localhost';`

