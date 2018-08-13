# 作业1

### 目的

**查找文件中连续最长的字符串（每个字符串由换行或空格隔开）。**

### 执行流程

**输入路径开始比较，如果文件存在进行下一步判断，如果是目录进行递归（进入这个目录，再次进行判断其中内容）， 如果是文件进行字符串比较储存最长字符**

### 还未解决的问题

**目前还没解决文件名存在空格的问题**

### 代码

```shell
#!/bin/bash

num=0
file=0
str=0

find() {
    for i in `ls`; do
        if [[ ! -e $i ]]; then # 判断是否存在 不存在执行下一次循环
           continue
        fi
        if [[ -d $i ]]; then # 如果是目录进行递归  
            cd $i
            find
            cd ..
            continue
        fi
        if [[ -f $i ]]; then # 如果是文件进行比较
            for j in `cat $i`; do
                if [[ ${#j} -gt $num ]]; then
                    num=${#j}
                    str=$j
                    file=`pwd`/$i
                fi
            done
        fi
    done
    return
}

cd $1
find

echo "字符串最长的文件路径："$file
echo "最长字符串的长度："$num
echo "最长的字符串："$str
```



### 执行结果

![2018-08-13 18-25-54屏幕截图](/home/x/图片/2018-08-13 18-25-54屏幕截图.png)

