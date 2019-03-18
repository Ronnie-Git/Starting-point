## lambda表达式

### 写法

`[捕获](参数){一些语句}`

- [捕获]：捕获主要控制lambda表达式的函数体可以看见外面的什么名字
- - `=`：需要的值都复制
  - `&`：需要的值都复制他们的引用，意味着你可以让你的lambda表达式使用外部的一个vector，并且还可以修改它
  - `this`：如果你的lambda表达式在一个类里，那么你还可以看到这个类，使用类成员的时候仍可以省略this指针
  - 省略：不需要可以不写
  - 其他情况：可以是`x`或`&x`，代表你是复制`x`还是复制`x`的引用；如需要看到`a、b、c`三个vector，外加一个字符串`x`，可写成`[&, x]`，`&`代表“所有使用的东西都把他的指针复制进去”，`x`代表“但是`x`要复制它的值”；还有不常用的，`[const auto& x = f(y)]`，把f(y)返回的一个引用复制进去，起个名叫x
- (参数)：就跟函数的参数一样。lambda表达式既然也是函数的一种，那他就可能需要参数
- {一些语句}：lambda表达式的函数体



### 代码

```c++
template<typename U>
void Traverse(vector<int>& xs, U process) {
    for (int x : xs) {
        process(x);
    }
}

void CopyGreaterThan(vector<int>& a, vector<int>& b, int y) {
    Traverse(a, [&, y](int x){
        if (x > y) {
            b.push_back(x);
        }
    });
}
```

