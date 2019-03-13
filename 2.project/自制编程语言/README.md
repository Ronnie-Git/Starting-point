****

# 正在维护当中。。。

****



## 一、环境需求

1. JAVA 1.8.0
2. Antlr 3.4
3. 支持 C++11 标准的编译环境
4. 系统无特殊需求



## 二、前导知识

1. EBNF文法
2. C/C++ 语言基础
3. 搜索算法基础
4. 面向对象程序设计思维



> java为什么要配置环境变量？
>
> 因为java是运行在java虚拟机上的，java虚拟机是用c写的，配置环境变量是给java虚拟机用的
>
>
>
> 将符合我们文法描述的文本建成一颗文法树
>
> 左孩子右兄弟
>
> 文法文件
>
> 词法分析器
>
> 抽象语法树



## 三、环境安装

**环境变量**是一种特殊的文件，会在程序运行的时候作为一种参数传进去



### 1、安装java (JDK)

#### 1.1 文件准备

##### 文件名称（根据 linux 版本和所需要的版本选择）

`jdk-8u121-linux-x64.tar.gz` 

#### 下载地址

http://www.oracle.com/technetwork/java/javase/downloads/jdk8-downloads-2133151.html

​    ![img](https://images2015.cnblogs.com/blog/380081/201703/380081-20170326175644315-996426123.png)

#### 1.2 操作步骤

* 解压文件：

```shell
tar zxvf jdk-8u121-linux-x64.tar.gz
```

* 使用vim编辑器，设置环境变量

```shell
sudo vim /etc/profile
```

* 在文件最后，添加如下内容：   

```
#Java Env
export JAVA_HOME=/usr/jdk1.8.0_121
export CLASSPATH=.:$JAVA_HOME/lib/dt.jar:$JAVA_HOME/lib/tools.jar
export PATH=$PATH:$JAVA_HOME/bin
```

* 退出vim编辑器，使环境变量设置立即生效

 ```shell
source /etc/profile
 ```

* 查看JDK版本

```shell
$ java -version
java version "1.8.0_121"
Java(TM) SE Runtime Environment (build 1.8.0_121-b13)
Java HotSpot(TM) 64-Bit Server VM (build 25.121-b13, mixed mode)
```



### 2、下载Antlr3.4

https://www.coder4.com/archives/4016

可以先建立一个目录，在该目录下下载Antlr

```shell
# 下载 Antlr 3.4 C 语言库以及文法转换过程中需要的 jar 包
wget http://www.antlr3.org/download/C/libantlr3c-3.4.tar.gz
wget http://www.antlr3.org/download/antlr-3.4-complete.jar

# 解压文件，tar.gz 说明用 tar 打包 gz 格式压缩，也有声明成 tgz 格式
tar -xzvf ./libantlr3c-3.4.tar.gz

# 进入 libantlr3c-3.4 目录后执行以下命令
./configure --enable-64bit
make
sudo make install
```



### 3、建立静态链接库

https://blog.csdn.net/weixin_40038847/article/details/78929254?utm_source=blogxgwz0

```shell
# 新建一个第三方的文件目录，同 libantlr3c-3.4 是同级目录
mkdir thirdpart

# 在 thirdpart 目录下新建两个文件目录
mkdir include # 这里面主要是放头文件的
mkdir libs # 这里面是放一个叫做 libantlr3c.a的静态链接库

# 在 thirdpart 目录下输入以下命令
cp ../libantlr3c-3.4/include/* ./include  # 这是把头文件拷贝到前面建好的头文件夹中
cp ../libantlr3c-3.4/.libs/libantlr3c.a ./libs # 这是拷贝静态链接库到新建的libs中
```



### 4、thirdpart/Makefile

```c++
CXX := g++
CFLAGS := -g #-wall
OBJS = *.cpp *.c
LIBA = ../thirdpart/libs/libantlr3c.a

test: 
	@$(CXX) $(CFLAGS) $(OBJS) $(LIBA) -o test -I. -I ../thirdpart/include/

.PHONY: clean install
clean:
	@rm test

install:
	@cp ../libantlr3c-3.4/include/* ./include
	@ cp ../libantlr3c-3.4/.libs/libantlr3c.a ./libs
```



