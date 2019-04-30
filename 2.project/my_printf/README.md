****

**正在维护当中。。。。。。**

****

### 任务需求

**用  c 语言通过 putchar 实现自己的 printf**



## 输出类型分析

### 输出 int 类型

#### 注意：

1. 正负数
2. 0
3. 整型最大值、整型最小值
4. 末尾为 0
5. 数字反转后大于整型最大值



#### 实现方法一 数组

```c
int my_printf_int1(int num) {
    unsigned int x = num; 
    if (num < 0) putchar('-'), x = -num;
    int ret = (x == 0 ? 1 : floor(log10(x)) + 1 + (num < 0));
    char temp[20] = {0};
    do {
        temp[++temp[0]] = x % 10 + '0';
        x /= 10;
    } while (x);
    while (temp[0]) {
        putchar(temp[temp[0]--]);
    }
    return ret; 
}
```



#### 实现方法二 数字倒置

* 使用 `unsigned int` 防止存不下整型最小值的绝对值
*  讲数字最后一位与前面分开，分成两部分存储，防止将数字倒置时越界

```c
int my_printf_int2(int num) {
    unsigned int x = num;
    if (num < 0) putchar('-'), x = -num;
   
    // 如果 num 为 0，那么 log10(0) 会出错，所以此时将其置为 1
    int ret = (x == 0 ? 1 : floor(log10(x)) + 1 + (num < 0));
	
    // 防止将数字倒置时越界
    unsigned int temp = 0, digit = 0, dx = x % 10;
    x /= 10;
    
    while (x) {
        temp = ((temp << 3) + (temp << 1)) + x % 10;
        x /= 10;
        digit += 1;
    }
    while (digit--) {
        putchar(temp % 10 ^ 48); // ^48 可以使 0~9 在数字和字符间相互转换
        temp /= 10;
    }
    putchar(dx + '0');
    return ret;
}
```

