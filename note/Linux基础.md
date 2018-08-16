# Linux基础

## 1.软件更新

1.源

Unix MAC APPStore 是闭源

`sudo apt-get update` 检测更新

`sudo apt-get upgrade` 更新

`sudo !!` 给前一条命令加权限

`.d` 文件 是目录

`sudo apt-get install *`  安装软件

`sudo apt-cache search * `  查找软件

## 2.命令

命令变量赋值时不能加空格

`ls`  查看当前目录文件

`cp` 拷贝

`mkdir` 创建目录

`touch` 创建空白文件

`cd .. ` 返回上一层  `cd -` 返回上一次进入的文件

`echo` 输出 打印

`cat` 强制读

`pwd` 输出路径

`/home` 不是家目录  `HOME` 家目录

`rm` 删除  `-f` 强制  `-r` 递归

`mv` 移动

`scp`  拷贝文件到远程主机

`port` 端口

`man`  查看使用手册

`tldr`  查看使用手册 （推荐使用  需要python-pip3 安装）

`grep “内容” ` 文件    检索文件内容

`df -h`  查看文件系统占用空间

`which` 查看命令在哪 `eg: which ls`

`type` 查看命令类型 `eg: type ls`

`history` 查看历史命令

`!编号`   执行该命令

`ctrl+r` 匹配最近的历史名命令

`date` 查看时间



`p` 管道  先进先出  出去就没了



## 3.ssh

下载`openssh-server`

`ssh-keygen`  生成公用密钥

`ifconfig` 查看本机IP地址

将本主机的`id_rsa.pub` 传到目标机器上的 `.ssh/authorized_keys` (使用`scp`传) (`ssh-copy-id -i ~/.ssh/id_rsa.pub 目标机器用户名@地址`)



## 4.vim

`shift+z` 挂起vim

`jobs`  查看挂起的有哪些

`fg 序号` 返回vim



`ps -ef | grep 内容`   (`ps -ef`是查看所有的进程的 然后用`grep`筛选出你要的信息)

`kill 名称`  杀死进程

`kill -9 名称`  强制杀死进程

`ctrl+c `  终止进程

`ctrl+z`  挂起进程

`bg`  把被中断的任务放在后台执行

`jobs`  查看挂起的有哪些

`fg 序号` 返回进程



## 5.装ubuntu系统

#### **创建主分区：**

**60G    主分区    空间起始位置    Ext4日志文件系统    /**

#### **创建swap分区：**

**4G    逻辑分区        空间起始位置    交换空间**

#### **创建boot分区：**

**500MB    逻辑分区   空间起始位置    Ext4日志文件系统   /boot**

#### **创建home分区:**

**10G    逻辑分区   空间起始位置    Ext4日志文件系统   /home**