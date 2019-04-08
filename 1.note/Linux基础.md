# Linux基础

## 1.软件更新

1.源

Unix MAC APPStore 是闭源

`sudo apt-get update` 检测更新

`sudo apt-get upgrade` 更新

`sudo !!` 给前一条命令加权限

`.d` 文件 是目录

`sudo apt-get install *`  安装软件

`sudo apt-get --purge remove` 删除软件及配置信息

`sudo apt-cache search * `  查找软件

`sudo apt-get install -f`  修复依赖关系

## 2.命令

命令变量赋值时不能加空格

`sudo updatedb`更新索引（本地文件） 查找文件时可用

`ls`  查看当前目录文件

`cp` 拷贝

`mkdir` 创建目录

`touch` 创建空白文件

`cd .. ` 返回上一层  `cd -` 返回上一次进入的文件

`eog 图片名` 查看图片



`echo` 输出 打印

`awk '{printf $第几个}'`  （以空格换行为分割符分成几部分）输出第几部分 

`cat` 强制读

`cut -d "" -f`     **`-d`用来定义分隔符，默认为`tab键`，`-f`表示需要取得哪个字段** 

eg: `echo "a/b/c" | cut -d '/' -f 1`   **执行结果是`a`** 

**先按`/`分段，第一个字段是`a`，第二个字段是`b`，第三个字段是`c`，`-f`就是取第几个字段，如果后面的是`-f 1-`，就是取后一字段`c`**



`pwd` 输出路径

`/home` 不是家目录  `HOME` 家目录



`rm` 删除  `-f` 强制  `-r` 递归

删除特殊字符的文件

`eg: "*"`   `rm \*` 用`\`转义



`mv` 移动



`scp`  拷贝文件到远程主机 `scp 文件名  远程主机名@远程主机IP:文件名`



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

`free -m`  查看内存占用



`p` 管道  先进先出  出去就没了



**`0 标准输入 ` `1 标准输出` `2 标准错误输出`**

 `>/dev/null 2>&1`   删除输出



`prtscr` 全屏幕截屏

`ctrl + prtscr` 窗口截屏

`shift + prtscr` 选取位置截屏



## 3.ssh

下载`openssh-server` 

**下载后打开服务别人能ssh到你，不然只能你ssh到别人**

`ssh-keygen`  生成公用密钥

`ifconfig` 查看本机IP地址

将本主机的`id_rsa.pub` 传到目标机器上的 `.ssh/authorized_keys` (使用`scp`传) (`ssh-copy-id -i ~/.ssh/id_rsa.pub 目标机器用户名@地址`)



ssh的配置文件

`    cat /etc/ssh/sshd_config`   

ssh服务的关闭

`    service sshd stop`

ssh服务的开启：

`    service sshd start`

ssh服务的重启

`    service sshd reload    [停止进程后重启] ==> 推荐`

`    service sshd restart   [干掉进程后重启] ==> 不推荐`

 

## 4.vim

`vimtutor` vim教程

`cril+z` 挂起vim

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



`:split(或sp) 文件名` vim 分屏(上下)

`:vsplit(或vsp) 文件名` vim 分屏(左右)

`ctrl + w` 切换这两个窗口



`esc` + `esc` 保存

**粘贴代码时格式不对，可以进入`Esc`模式，`:set paste`   `ctrl + v`  粘贴**



**插入列**

插入操作的话知识稍有区别。例如我们在每一行前都插入"() "：

1. 光标定位到要操作的地方。

2. CTRL+v 进入“可视 块”模式，选取这一列操作多少行。

3. SHIFT+i 输入要插入的内容。

4. ESC 按两次，会在每行的选定的区域出现插入的内容。



**vim加密**

进入vim，输入`:X` 之后就提示你输入两次密码。之后`:wq`保存退出。再次进入时就提示你输入密码了。如果你不想要密码了，就`:X `提示你输入密码时**连续按两次回车**



| 一般模式下，快捷键        |                                    |
| ------------------------- | ---------------------------------- |
| v                         | 字符选择，将光标经过的字符选择     |
| V                         | 行选择，将光标经过的行选择         |
| ctrl+v (ctrl + shift + v) | 矩形选择，可以用矩形的方式选择数据 |
| y                         | 将选中地方复制起来                 |
| d                         | 将选中地方删除                     |
| G(shift+g)                | 跳到文本的最后一行                 |
| gg                        | 跳到第一行的第一个字符             |
| ngg 或 nG                 | 跳到第n行                          |
| u                         | 撤销                               |
| ctrl+r                    | 回到撤销之前                       |



## 5.装ubuntu系统

#### **创建主分区：**

**60G    主分区    空间起始位置    Ext4日志文件系统    /**

#### **创建swap分区：**

**4G    逻辑分区        空间起始位置    交换空间**

#### **创建boot分区：**

**500MB    逻辑分区   空间起始位置    Ext4日志文件系统   /boot**

#### **创建home分区:**

**10G    逻辑分区   空间起始位置    Ext4日志文件系统   /home**