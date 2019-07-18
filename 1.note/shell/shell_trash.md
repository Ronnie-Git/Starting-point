# 作业2

## 目的

**自制垃圾桶 安全的rm**

## 执行方式

**./该shell文件名   后加参数同rm规则**

## 还未解决的问题

**垃圾桶还不能够定时清理**

**输入的参数只能是文件名或目录 不能加路径**

## 代码

****

```shell
#!/bin/bash

if [[ ! -d ~/.trash ]]; then # 如果不存在.trash文件 建立.trash文件
    mkdir ~/.trash
fi

if [[ $# -eq 0 ]]; then
    echo "没有输入文件名" # 提示输入文件名
elif [[ $1 = "-r"  &&  $2 = "-f*" ]]; then # 判断是否含有 -r -f* 命令 
    for file in `ls`; do # 遍历所有参数
        if [[ -f "$file"  ||  -d "$file" ]]; then 
            mv -b "$file" ~/.trash/ # 如果是文件或目录 移动到.trash
            else 
                echo "没有找到文件或目录："$file # 如果不存在 输出没有找到文件或目录
        fi
    done
elif [[ $1 = "-f" ]]; then # 判断是否含有 -f 命令
    for file in "$@"; do # 遍历所有参数
        if [[ $file != "-f" ]]; then 
            mv -b "$file" ~/.trash/ # 移动文件到.trash
        fi
    done
else 
    read -p "确定要删除吗？[Y/n]：" answer
    if [[ "$answer" = "Y" || "$answer" = "y" ]]; then # 判断是否进行删除
        for file in "$@"; do # 遍历所有参数
            if [[ -f "$file"  ||  -d "$file" ]]; then
                mv -b "$file" ~/.trash/
                else
                    echo "没有找到文件或目录："$file
            fi
        done
        else
            echo "已取消删除"    
    fi
fi
```



