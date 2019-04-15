### if分支预测（cpu分支预测）

参考网址：https://blog.csdn.net/qq_22237829/article/details/74279667



```c
#ifdef __GNUC__  
#define LIKELY(x)           (__builtin_expect(!!(x), 1))  
#define UNLIKELY(x)         (__builtin_expect(!!(x), 0))  
#else  
#define LIKELY(x)           (x)  
#define UNLIKELY(x)         (x)  
#endif  
```



LIKELY 作用是告诉编译器 x表达式更有可能是真的，也就是有很大的几率是运行if分支的。

UNLIKELY 作用是告诉编译器 x表达式更有可能是假的，也就是有很大的几率是运行else分支的。

这样的好处是如果if-else分支预测正确时，可以大大提高程序运行的效率。

