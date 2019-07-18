## 头文件

### `<dirent.h>` 

https://blog.csdn.net/dream_allday/article/details/75243818

```c
#include <dirent.h>
DIR *opendir(const char *dirname);
struct dirent *readdir(DIR *dirp);
int closedir(DIR *dirp);
```

**`opendir`用于打开目录，是类似于流的那种方式，返回一个指向`DIR结构体的指针`**

**参数`*dirname`是一个字符数组或者字符串常量；**

**`readdir`函数用于读取目录，只有一个参数，就是`opendir`返回的结构体指针，或者叫句柄更容易理解些吧。这个函数也返回一个结构体指针 `dirent *`；**



：