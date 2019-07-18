## c 和 c++ 对比

### c语言

`f()` 可传任意参数

`g(void)` 不能传参

`struct` 定义结构体 成员中不可以有函数

可以定义多个同样名字的变量



```c
#include <stdio.h>

int a;
int a;
int a;
// 可以定义多个同样名字的变量

int f() {
    return 3;
}

int g(void) {
    printf("Hello\n");
}

int main() {
    printf("%d\n", f(1, 2, 3, 6));
    g(1, 2, 3, 5); // 错误，应该g();
    return 0;
}
```



```c
#include <stdio.h>

struct student {
    void f() {
        printf("Hello!\n");
    }
} stu;

int main() {
    stu.f(); // 编译不会通过
    return 0;
}
```





c89 

```c
int i;
for (i = 0; i < 10; i++) {}
```



c99  和 c11

```c
for (int i = 0; i < 10; i++) {}
```







### c++

`f()` 不能传参

`g(void)` 不能传参

`struct` 定义结构体（也是一个类）成员中可以有函数

不可以定义多个同样名字的变量



```c++
#include <iostream>
#include <cstdio>
using namespace std;

int a;
int a;
int a;
// 不可以定义多个同样名字的变量

int f() {
    return 3;
}

int g(void) {
    printf("Hello\n");
}

int main() {
    printf("%d\n", f(1, 2, 3, 6)); // 错误，应该f();
    g(1, 2, 3, 5); // 错误，应该g();
    return 0;
}
```



```c++
#include <iostream>
#include <cstdio>

using namespace std;

struct student {
    void f() {
        printf("Hello!\n");
    }
} stu;

int main() {
    stu.f();
    return 0;
}
```





## c++

* c语言 头文件：29个

* 头文件：58个

* 异常处理： 异常类便于调试

* 类和对象

* STL

* 模板

* Lambda



| 编程范式     | c    | c++  |
| ------------ | ---- | ---- |
| 面向过程编程 | yes  | yes  |
| 面向对象编程 | no   | yes  |
| 泛型编程     | no   | yes  |
| 函数式编程   | no   | yes  |



### 输出小数

```c++
#include <iomanip>
using namespace std;
int main() {
	cout << setprocision(2) << fixed << 结果 << endl;
	return 0;
}
```





## STL

### queue 类

queue 类：队列

​	头文件：`<queue>`

​	命名空间：std

​	声明：`queue<data_type> q;`

| 调用函数方式 | 函数功能     |
| ------------ | ------------ |
| q.front()    | 查看队首元素 |
| q.empty()    | 队列判空     |
| q.push()     | 入队         |
| q.pop()      | 出队         |
| q.size()     | 队列元素数量 |





### stack 类

stack 类：栈

​	头文件：`<stack>`

​	命名空间：`std;`

​	声明：`stack<data_type> s;`	



| 调用函数方式 | 函数功能     |
| ------------ | ------------ |
| s.top()      | 查看栈顶元素 |
| s.empty()    | 栈判空       |
| s.push()     | 入栈         |
| s.pop()      | 出栈         |
| s.size()     | 栈元素数量   |





### string 类

string 类：字符串

​	头文件：`string`

​	命名空间：`std;`

​	声明：`string s1, s2;`



| 用法        | 解释       |
| ----------- | ---------- |
| s1 == s2    | 字符串判等 |
| s1 < s2     | 字典序小于 |
| s1 > s2     | 字典序大于 |
| s1 += s2    | 字符串链接 |
| s1.length() | 字符串长度 |





### hash_map 类（非标准）

hash_map 类：字符串

​	头文件：	`<hash_map> / <ext/hash_map>`

​	命名空间：`__gnu_cxx;`

​	声明：`hash_map<key_type, value_type, hash_func> h;`



| 函数           | 用法                          |
| -------------- | ----------------------------- |
| h.find(key)    | 判断某个key值是否在hash_map中 |
| h[key] = value | 将value存储在key位上          |
| h[key]         | 访问key值对应的value          |
| h.begin()      | 哈希表的起始位置              |
| h.end()        | 哈希表的结束位置              |



### unordered_map 类（非标准）

hash_map 类：字符串

​	头文件：	`unordered_map`

​	命名空间：`std`

​	声明：`hash_map<key_type, value_type, hash_func> h;`



| 函数           | 用法                          |
| -------------- | ----------------------------- |
| h.find(key)    | 判断某个key值是否在hash_map中 |
| h[key] = value | 将value存储在key位上          |
| h[key]         | 访问key值对应的value          |
| h.begin()      | 哈希表的起始位置              |
| h.end()        | 哈希表的结束位置              |



