## 赋予普通用户root权限

### 方法一

1. 命令

```shell
vi /etc/sudoers
```

2. 在`root    ALL=(ALL)     ALL`下面添加一行

```
## Allow root to run any commands anywhere
root    ALL=(ALL)     ALL
admin   ALL=(ALL)     ALL
```

**修改后admin用户可以通过sudo获得管理员权限**

> root    ALL=(ALL)	ALL 
>
> root表示被授权的用户，这里是根用户； 
> 第一个ALL表示所有计算机；
> 第二个ALL表示所有用户；
> 第三个ALL表示所有命令；



### 方法二

1. 命令

```shell
vi /etc/passwd
```

2. 把用户ID修改为 0

```shell
# admin:x:500:500:admin:/home/tommy:/bin/bash
# 将上行修改为
admin:x:0:500:admin:/home/tommy:/bin/bash
```

**修改后admin用户可以通过sudo获得管理员权限**