## 值类型

是指一个对象可以像`int`一样，可以被构造、复制、传递，不用用户担心`new`和`delete`的问题。

* 值类型对象能够被构造和析构，保证对应用者是可见的
* 如果将析构函数藏起来（放在`private`里），还想将该对象做成值类型，是没有意义的



```c++
class String {
public:
    String();
    String(const char*);
    String(const String&);
    String(String&&);
    ~String();

    String& operator=(const String&);
    String& operator=(String&&);

    bool operator==(const String&)const;
    bool operator!=(const String&)const;
    bool operator<(const String&)const;
    bool operator<=(const String&)const;
    bool operator>(const String&)const;
    bool operator>=(const String&)const;

    const char* GetBuffer()const;
    size_t GetLength()const;
    String operator+(const String&)const;
    String SubString(int start, int length)const;

    /* ... * /
};
```

**注意**：

* `String(const String&);`，要先开辟空间，再将字符串的内容复制过去，否则两个`String`实例共享同一个指针，两个析构函数分别`delete[]`两次会发生异常
* `~String();`，对`nullptr`调用`delete`或者`delete[]`都不会发生异
* `String(const char*);`，不能直接将`const char*`的指针复制给`char*`的指针，因为类型不兼容，要先开辟空间，再将字符串的内容复制过去。如果只复制一个指针的话，有可能它就是`main`函数里面的`"hello world"`，而这种字符串指针无法被`delete[]`



## 左值和右值

右值引用是指**已经不需要再被用到的对象的引用**



#### 右值引用的复制构造函数（移动构造函数）

```c++
String& operator=(String&& theString) {
    if (this != &theString) {
        delete[] buffer;
        length = theString.length;
        buffer = theString.buffer;
        theString.buffer = nullptr;
    }
    return *this;
}
```

**直接把它的指针拿过来，再把它的指针指向`nullptr`**，这样便可以保证析构函数正常运行



#### 需要返回右值的表达式

* 除非是在`return`	一个全局变量的时候，否则变量名肯定不是右值，因为它可以在这个表达式之后被反复使用。
* 表达式返回值是左值引用，肯定不是右值，因为别人可能也会拥有这个引用。不能在函数里返回局部变量的左值引用
* 表达式的返回值是一个值类型，当对这个表达式求值的时候，返回值所代表的对象可以被看成一个右值
* 表达式的返回值是右值引用的，肯定 是右值。但我们不要看到`T&&`就认为这一定是一个右值的引用，如果`T`代表的是`U&`的话，那么它还是左值，因为`U& &&`其实相当于`U&`，这就叫**引用折叠**
* 大部分时候都是右值

