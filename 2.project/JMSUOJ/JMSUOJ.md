### 参考博客和文档

* UOJ部署指北 https://universaloj.github.io/
* svn简易指北 [https://universaloj.github.io/post/SVN%E7%AE%80%E6%98%93%E6%8C%87%E5%8C%97.html](https://universaloj.github.io/post/SVN简易指北.html)
* linux搭建svn
  * https://blog.csdn.net/sm_wang/article/details/78656120
  * https://www.cnblogs.com/-mrl/p/8980244.html





## 一、安装`docker`

您需要准备一台**64位**的Linux系统，这里建议您使用 [Ubuntu](https://www.ubuntu.com/)。

然后您需要安装`docker`。它是一个容器技术，暂且可以理解成虚拟机。

```shell
curl -fsSL get.docker.com -o get-docker.sh
sudo chmod +x get-docker.sh
sudo ./get-docker.sh

sudo service docker start           # 启动docker服务
```

另外，您可以通过下面的代码安装docker加速器（强烈推荐）：

```shell
sudo su
curl -sSL https://get.daocloud.io/daotools/set_mirror.sh | sh -s http://3a834d99.m.daocloud.io
service docker restart
```



## 二、安装`uoj`

### 1.安装

您需要执行下面的指令来开始安装 UOJ：

```shell
sudo docker pull universaloj/uoj-system
sudo docker run --name uoj -dit -p 80:80 -p 3690:3690 --cap-add SYS_PTRACE universaloj/uoj-system
```

接下来，UOJ将在后台运行。

> 上面的代码是用于**新建一个 UOJ 容器**，重启服务器后**不要**使用`docker run`来启动容器。具体参阅维护文档。
> 如果您不希望用80端口来运行uoj，您可以把上面的`-p 80:80`改成`-p <port>:80`。

稍等几分钟，访问服务器的地址，您现在应该能看到UOJ正在运行了。

**您注册的第一个用户将被自动设为管理员。**



### 2.更改 logo

##### 1) 为uoj代码库添加一位管理和密码

LOGO 图片位于网站的`/picture`目录下，使用 SVN 管理。

UOJ 代码的 SVN 仓库地址是：`svn://<local-uoj-address>/uoj`（网页部分）和 `svn://local_uoj.ac/judge_client`（主评测机部分）。

UOJ 代码仓库需要您手动添加权限。
首先，您需要进入 Docker 容器，运行下面的命令：

```shell
echo "uoj=666666" >>/var/svn/uoj/conf/passwd    #增加一位名为 "uoj"，密码为 "666666" 的 svn 仓库管理员
```

**注意**：请不要在 Docker 容器中修改除 `.config.php` 以外的文件，这样可能导致 SVN 仓库混乱。

##### 2) 需要 checkout UOJ 的 web 目录

```shell
svn checkout svn://<local-uoj-address>/uoj
cd uoj/1/pictures
```

在 `/pictures` 目录下替换对应的图片，然后 commit。

```shell
svn commit -m "Changed logo" *
```



### 3.准备题目

#### 1) 准备数据

对于传统题，您上传的`×.zip`数据包应当包括这些内容：

- 题目配置文件
- 测试数据
- 额外测试数据（包括题面中所给的测试样例）
- （开启 hack）数据检验器
- （开启 hack）标准程序

##### 题目配置文件

题目配置文件应当命名为`problem.conf`。这是一份配置的样例：

```
n_tests 10
n_ex_tests 1
n_sample_tests 1
input_pre www
input_suf in
output_pre www
output_suf out
time_limit 1
memory_limit 512
output_limit 64
use_builtin_judger on
use_builtin_checker ncmp
```

##### 测试点

```
n_tests 10
n_ex_tests 1
n_sample_tests 1
```

这三行分别代表标准测试点、额外测试点和测试样例的数量。其中，额外测试点的前几个一定是测试样例，所以你必须把题目中给出的测试样例放到额外测试点当中。

UOJ 的 extra test 是指在 AC 的情况下会测额外数据，如果某个额外数据通不过会被倒扣3分。

```
input_pre www
input_suf in
output_pre www
output_suf out
```

这四行分别指明了每个测试点输入文件的前缀、扩展名、输出文件的前缀、扩展名。

标准测试点的文件名应当形如：`www1.in`、`www1.out`、`www2.in`、`www2.out`……

额外测试点的文件名应当形如：`ex_www1.in`、`ex_www1.out`、`ex_www2.in`、`ex_www2.out`……

##### 限制

```
time_limit 1
memory_limit 512
output_limit 64
```

这三行配置了评测时对选手程序的时间限制、内存空间限制和输出限制。

时间限制的单位为秒，不能为小数。内存空间和输出限制的单位为 MB。

##### 校验器（checker）

校验器用来检查选手程序的输出是否正确。

```
use_builtin_judger on
use_builtin_checker ncmp
```



#### 2) 在网页上提交*.zip文件



#### 3) 通过svn

根据`var/svn/problem/题号/conf/passwd`文件找到svn管理员用户名和密码

```shell
svn co svn://svn地址 [本地目录全路径] --username 用户名 --password 密码
```

**还未完成svn上传题目。。。**





## 三、安装`svn`

### 1.安装SVN

```shell
sudo apt-get install subversion
```



### 2.创建SVN版本库

1) 创建home下的svn文件夹

```shell
sudo mkdir  /home/svn
```

2) 创建svn下的repository文件夹

```shell
sudo mkdir  /home/svn/repository
```

3) 更改repository的权限（第一次搭建没有赋予权限，客户端访问服务器被拒绝）

```shell
sudo chmod -R 777 /home/svn/repository
```

4) 创建版本库

```shell
sudo svnadmin create /home/svn/repository
```

5) 然后对db进行权限设置

```shell
sudo chmod -R 777 db
```



#### 设置访问权限：需要对`conf`文件夹下的文件进行修改

1) 修改配置文件`conf/svnserve.conf`

```shell
sudo vim /home/svn/repository/conf/svnserve.conf
```

```shell
#匿名用户可读
anon-access = read（可改成none，即不可读）
#权限用户可写
auth-access = write
#密码文件为passwd
password-db = passwd
#权限文件为authz
authz-db = authz
```

**去掉前面的#，并且顶格，不然可能会报错**

2) 添加访问用户`conf/passwd`

```shell
sudo vim /home/svn/repository/conf/passwd 
```

```shell
[users]
zhangsan = 123456
```

3) 设置用户权限`conf/authz`

```shell
sudo vim /home/svn/repository/conf/authz
```

```shell
[groups]
admin = zhangsan   # 用户zhangsan属于admin权限组

[/]
@admin = rw        # admin权限组对根目录权限是读和写
* = rw             # 所有的组都具有读权限和写权限
```



### 3.测试SVN服务器

1) 启动服务器

```shell
svnserve -d -r /home/svn  #-d：表示在后台运行 ，-r：指定服务器的根目录
```


查看`svnserve`是否已经运行

```shell
ps aux | grep svnserve
```

> 如果服务器已经在后台运行了，就可通过`svn://服务器ip/repository`从`svn`客户端访问服务器了



2) 停止服务器

如果需要关闭服务器，可以用下面的命令

```shell
killall svnserve
```