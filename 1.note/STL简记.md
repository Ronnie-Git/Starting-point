##  几种重要的算法，使用时需要包含头文件：

头文件`<algorithm>`

| 使用方式                              | 解释                                                         |
| :------------------------------------ | ------------------------------------------------------------ |
| sort(a.begin(), a.end())              | 对a中的从a.begin()（包括它）到a.end()（不包括它）的元素进行从小到大排列 |
| reverse(a.begin(), a.end())           | 对a中的从a.begin()（包括它）到a.end()（不包括它）的元素倒置，但不排列，如a中元素为1,3,2,4,倒置后为4,2,3,1 |
| copy(a.begin(), a.end(), b.begin()+1) | 把a中的从a.begin()（包括它）到a.end()（不包括它）的元素复制到b中，从b.begin()+1的位置（包括它）开始复制，覆盖掉原有元素 |
| find(a.begin(), a.end(), 10);         | 在a中的从a.begin()（包括它）到a.end()（不包括它）的元素中查找10，若存在返回其在向量中的位置 |



## stack

stack 模板类的定义在`<stack>`头文件中。
stack 模板类需要两个模板参数，一个是元素类型，一个容器类型，但只有元素类型是必要的，在不指定容器类型时，默认的容器类型为deque(双端队列)



### 定义stack 对象的示例代码

```c++
stack<int> s1;
stack<string> s2;
```



### stack 的基本操作有

| 使用方式  | 解释                                                 |
| --------- | ---------------------------------------------------- |
| s.push(x) | 入栈                                                 |
| s.pop()   | 出栈，注意，出栈操作只是删除栈顶元素，并不返回该元素 |
| s.top()   | 访问栈顶                                             |
| s.empty() | 判断栈空，当栈空时，返回true                         |
| s.size()  | 访问栈中的元素个数                                   |

 

## queue

queue 模板类的定义在`<queue>`头文件中。
与stack 模板类很相似，queue 模板类也需要两个模板参数，一个是元素类型，一个容器类
型，元素类型是必要的，容器类型是可选的，默认为deque 类型。



### 定义queue 对象的示例代码

```c++
queue<int> q1;
queue<double> q2;
```



### queue 的基本操作

| 使用方式  | 解释                                                         |
| --------- | ------------------------------------------------------------ |
| q.push(x) | 入队，将x 接到队列的末端。                                   |
| q.pop()   | 出队，弹出队列的第一个元素，注意，并不会返回被弹出元素的值。 |
| q.front() | 访问队首元素，即最早被压入队列的元素。                       |
| q.back()  | 访问队尾元素，即最后被压入队列的元素。                       |
| q.empty() | 判断队列空，当队列空时，返回true。                           |
| q.size()  | 访问队列中的元素个数                                         |



## priority_queue

在`<queue>`头文件中，还定义了另一个非常有用的模板类priority_queue(优先队列）。优先队列与队列的差别在于优先队列不是按照入队的顺序出队，而是按照队列中元素的优先权顺序出队（默认为大者优先，也可以通过指定算子来指定自己的优先顺序）。
priority_queue 模板类有三个模板参数，第一个是元素类型，第二个容器类型，第三个是比较算子。其中后两个都可以省略，默认容器为vector，默认算子为less，即小的往前排，大的往后排（出队时序列尾的元素出队）。



### 定义priority_queue 对象的示例代码如下

```c++
priority_queue<int> q1; 
priority_queue< pair<int, int> > q2; // 注意在两个尖括号之间一定要留空格。
priority_queue<int, vector<int>, greater<int> > q3; // 定义小的先出队
```



### priority_queue 的基本操作与queue 相同

初学者在使用priority_queue 时，最困难的可能就是如何定义比较算法了。如果是基本数据类型，或已定义了比较运算符的类，可以直接用STL 的less 算子和greater算子——默认为使用less 算子，即小的往前排，大的先出队。如果要定义自己的比较算子，方法有多种，这里介绍其中的一种：重载比较运算符。优先队列试图将两个元素x 和y 代入比较运算符(对less 算子，调用x<y，对greater 算子，调用x>y)，若结果为真，则x 排在y 前面，y 将先于x 出队，反之，则将y 排在x 前面，x 将先出队。



## deque

头文件`<deque>`

考虑到deque的特殊结构，所以实现deque的各种操作都相当琐碎复杂。最关键的就是判断是否已经处于缓冲区边缘，如果是，一旦前进或后退就必须跳跃至下一个或上一个缓冲区。还有一个重要问题就是当map前端或尾端备用空间不足时就要重新配置新map（配置更大的，拷贝原来的，释放原来的），下面的push_back()和push_front()等函数都需要先判断。下面分别解释deque的各个成员函数。

- push_back()：当最后缓冲区有两个（含）以上的空间，直接在缓冲区增加新元素；当最后缓冲区**只剩一个备用空间**时，push_back()调用push_back_aux()，先配置一个新的缓冲区，然后再在那个仅剩的备用空间定义新元素，并更改finish的状态，令其指向新结点。
- push_front()：当第一缓冲区有备用空间时，直接在备用空间增加新元素；当第一缓冲区无备用空间时，调用push_front_aux()配置新结点（缓冲区），增加新元素，并改变start状态。
- pop_back()：当最后缓冲区有一个（含）以上元素，就将finish向前移一位并将最后那个元素析构掉；当最后缓冲区没有任何元素，就调用push_pop_aux()将这个缓冲区释放。解释一下：第一种情况finish指向最后缓冲区的first位置，第二种情况finish指向最后第二个缓冲区的last位置。
- pop_front()：第一缓冲区有两个（含）以上元素，将第一个元素析构，将start后移；否则，将这个缓冲区释放，start指向下一个缓冲区第一个元素。
- clear()：deque的最初状态（即无任何元素时）保有一个缓冲区，因此clear()之后也一样要保留一个缓冲区，finish=start。
- erase()：先判断清除空间前后元素个数，移动较少一端。
- insert()：若在最前端，即push_front()，最后端类似；判断插入点前后元素个数，移动较少的一端。



## vector

vector 是向量类型，它可以容纳许多类型的数据，如若干个整数，所以称其为容器。vector 是C++ STL的一个重要成员，使用它时需要包含头文件：

头文件`<vector>`



### vector 的初始化：可以有五种方式

```c++
vector<int> a(10); 
//定义了10个整型元素的向量（尖括号中为元素类型名，它可以是任何合法的数据类型），但没有给出初值，其值是不确定的。

vector<int> a(10,1);
//定义了10个整型元素的向量,且给出每个元素的初值为1

vector<int> a(b);
//用b向量来创建a向量，整体复制性赋值

vector<int> a(b.begin(), b.begin+3);
//定义了a值为b中第0个到第2个（共3个）元素

int b[7]={1,2,3,4,5,9,8};
vector<int> a(b,b+7); //从数组中获得初值
```



###  vector对象的几个重要操作

```c++
a.assign(b.begin(), b.begin()+3); //b为向量，将b的0~2个元素构成的向量赋给a
a.assign(4,2); //是a只含4个元素，且每个元素为2

a.back(); //返回a的最后一个元素
a.front(); //返回a的第一个元素
a[i]; //返回a的第i个元素，当且仅当a[i]存在2013-12-07
a.clear(); //清空a中的元素
a.empty(); //判断a是否为空，空则返回ture,不空则返回false
a.pop_back(); //删除a向量的最后一个元素

a.erase(a.begin()+1,a.begin()+3);
//删除a中第1个（从第0个算起）到第2个元素，也就是说删除的元素从a.begin()+1算起（包括它）一直到a.begin()+         3（不包括它）

a.push_back(5); //在a的最后一个向量后插入一个元素，其值为5

a.insert(a.begin()+1,5);
//在a的第1个元素（从第0个算起）的位置插入数值5，如a为1,2,3,4，插入元素后为1,5,2,3,4

a.insert(a.begin()+1,3,5);
//在a的第1个元素（从第0个算起）的位置插入3个数，其值都为5

a.insert(a.begin()+1,b+3,b+6);
//b为数组，在a的第1个元素（从第0个算起）的位置插入b的第3个元素到第5个元素（不包括b+6），如b为1,2,3,4,5,9,8         ，插入元素后为1,4,5,9,2,3,4,5,9,8

a.size(); //返回a中元素的个数；
a.capacity(); //返回a在内存中总共可以容纳的元素个数

a.resize(10); //将a的现有元素个数调至10个，多则删，少则补，其值随机
a.resize(10,2); //将a的现有元素个数调至10个，多则删，少则补，其值为2

a.reserve(100);
//将a的容量（capacity）扩充至100，也就是说现在测试a.capacity();的时候返回值是100.这种操作只有在需要给a添加大量数据的时候才         显得有意义，因为这将避免内存多次容量扩充操作（当a的容量不足时电脑会自动扩容，当然这必然降低性能） 

a.swap(b); //b为向量，将a中的元素和b中的元素进行整体性交换
a==b;
//b为向量，向量的比较操作还有!=,>=,<=,>,<[![复制代码](http://common.cnblogs.com/images/copycode.gif)](javascript:void(0);
```

 

## map

头文件`<map>`

map 是一种有序无重复的关联容器。

关联容器与顺序容器不同，他们的元素是按照关键字来保存和访问的，而顺序元素是按照它们在容器中的位置保存和访问的。

map保存的是一种 key - value 的pair对象，其中 key 是关键字，value 是关键字对应的值。通过 key找到对应的 value。map中按照 key的大小升序排列pair对象。

```c++
typedef pair<const Key, T> value_type
```

其中key 是 const的，即不可以改变map中的key。

在map中定位特定的元素比 unordered_map 要慢，因为在 map中需要根据 key的大小进行顺序查找。

但是在map中允许直接选取一定范围的元素。

map在底层通常用二叉搜索树实现。

```c++
template < class Key,
			// map::关键字类型
           class T,
			// map::值类型
           class Compare = less<Key>,
			// map::关键字比较函数
           class Alloc = allocator<pair<const Key,T> >
            // map::allocator类
           > class map;
```

模板参数的第三个 `class Compare = less<Key>` 是一种比较函数

通过这个比较函数，map能比较两个不同的 key值的大小关系，及是否相等。默认采用 `less<Key>`， 即 Key 类型的 "<"操作符。

如果 Key类型没有"<"操作符的定义，则需要提供一个自定义比较函数的函数指针，来作为Compare函数。



### 构造函数

1. 默认构造： `map<Key, value> m;`　　构造一个空的map，注意，必要时要给出模板参数中的 Compare。需要时给出 Alloc

2. 范围构造：` map<key, value> m(iterator first, iterator last);`　　将迭代器[frist, last)范围内的元素填入map中

3. 拷贝构造： `map<key, value> m(cosnt map& m2);`　　用m2构造m

4. 初始化列表构造： `map<key, value> m(initializer_list<value_type> il)`

   由于map 的 value_type 是 pair类型，所以要构造成pair作为列表，这是三种构造 pair的方式

   ```c++
   map<key, value> m{{key k1, value v1},{k2, v2}, ...}　　// 通过 {}构造 pair
   
   map<key, value> m{make_pair(key k1, value v1), make_pair(k2, v2), ...}　　// 通过 make_pair() 函数构造 pair
   
   map<key, value> m{pair<key, value>(k1, v1), pair<key, value>(k2, v2), ...}　　// 通过类型转换构造 pair　　　　　　　　 
   ```



### 赋值操作符=

```c++
map& operator= (const map& x)　  // map赋值
map& operator= (map&& x)　　　　// 不懂
map& operator= (initializer_list<value_type> il)　　// 参数列表赋值
```



### 迭代器

1. `begin, end, rbegin, rend`

2. `cbegin, cend, crbegin, crend`



#### 注意

* map 的迭代器支持 ++, -- 操作，但是不支持 +i 操作。
* map中是根据 key的值来排列元素的位置的，所以通过迭代器遍历出来的结果顺序，可能和插入值的顺序不同。
* 对 map的迭代器解引用的结果是得到一个 pair类型的对象。它有两个共有成员 first, second。first保存 key的值，second 保存value的值。
* 由于map的 key 是 const的，所以得到的 pair 的first 也是const 的。



### 成员函数

#### 容量

```c++
empty()		// 如果map 为空，返回true。否则返回 false
			bool empty() const noexcept;

size()　　　 // 返回map 中元素的大小，即 key-value 的个数
　　　　　　　size_type size() const noexcept;

max_size()  // 返回由于存储空间的限制，map有可能包含的最大元素数。但不保证一定能达到这个数量，有可能在中途申请空间失败。
			size_type max_size() const noexcept;
```

　　　　　　　　　　　　

#### 元素访问

```c++
操作符[]　　m[k] //返回map 中 Key为 k的元素的value的引用。
　　　　　　// 如果 k不存在，那么将会插入一个 key为 k的元素，并返回其默认 value。
　　　　　　// []操作总会将 map的大小 +1
　　　　　　// 注意，对于map，解引用迭代器得到 pair，操作符[]得到 value

at()　　　 m.at(k) //返回map中Key为k的元素的value的引用。
　　　　　　// 如果k不存在，抛一个 out_of_range 异常。
　　　　　　// 使用 at 不会添加元素，不会增加 map的大小
```



#### 修改

```c++
insert　　插入
		(1) pair<iterator, bool> insert(const pair<key, value> &val);
　　　　　　 // 单个值插入，参数为 pair类型，first 为 key, second为 value
　　　　　　 // 返回值也是一个 pair，first为插入后的 iterator，second 为bool类型， true表示插入成功，false 表示插入失败
　　　　　　 // 插入失败是因为 map 中已经有一个 key 与输入相同。这次插入操作对map 不会有任何影响， 失败时返回值的 first指向已有的key-value

　　　　　(2) iterator insert(const_iterator pos, const pair<key, value> &val);
　　　　　　  // 提示值插入
　　　　　　  // 从 pos 指定的位置开始查找 val应该插入的位置
　　　　　　  // 如果设定值合适，可以减少插入时做查找的时间

　　　　　(3) void insert(iterator first, iterator second);
　　　　　　  // 范围插入，插入[first, second)范围内的内容

　　　　　(4) void insert(initializer_list<value_type> il);
　　　　　　  // 初始化列表插入

emplace　　高效插入
		/*
　　　　  和 insert的主要区别在于，insert首先构造一个临时 value_type对象，再copy到 map中。
　　　　  而emplace 是直接在map里根据参数构造 value_type对象。更高效。
　　　　  pair<iterator, bool> emplace(key k, value v);
　　　　  返回值与 insert情况相同。
		*/
		
emplace_hint　　提示位置的高效插入
		/*
　　　　  iterator emplace(const iterator pos, key k, value v);
　　　　  从pos开始查找应该插入的位置，其余和 emplace相同。
		*/

erase　　删除
　　　　  (1) iterator erase(const_iterator position);
		// 删除迭代器指向的内容, 函数返回 NULL

　　　　  (2) iterator erase(const_iterator first, const_iterator last);
		// 删除迭代器范围内的内容，函数返回NULL

　　　　  (3) size_type erase(const key_type &k);
		// 删除 type 为k的元素，返回删除的数目。对于 map，成功删除返回1，k不存在则返回0

　　　　  (4) 1，2中如果迭代器无效，会产生 undefined behavior

swap　　交换两个 map对象的内容
　　　　  (1) void swap(map &x)

　　　　  (2) void swap(map &x1, map &x2)　　// 非成员重载函数

clear　　清空一个容器的所有元素
　　　　  void clear() noexcept;
```



#### 操作

```c++
find　　查找
		//在map中查找key 为 k的元素，返回指向它的迭代器。若k不存在，返回 map::end.
　　　　　iterator find(const key_type &k);

count　 计数
		//统计map中 key为k的元素的个数，对于map，返回值不是1(存在)，就是0(不存在)
　　　　　size_type count(const key_type &k) const;
```



## set

头文件`<set>`

关于set，必须说明的是set关联式容器。set作为一个容器也是用来存储同一数据类型的数据类型，并且能从一个数据集合中取出数据，在set中每个元素的值都唯一，而且系统能根据元素的值自动进行排序。应该注意的是set中数元素的值不能直接被改变。C++ STL中标准关联容器set, multiset, map, multimap内部采用的就是一种非常高效的平衡检索二叉树：红黑树，也成为RB树(Red-Black Tree)。RB树的统计性能要好于一般平衡二叉树，所以被STL选择作为了关联容器的内部结构。



### set使用方法

| 使用方法               | 解释                                                         |
| ---------------------- | ------------------------------------------------------------ |
| s.begin()              | 返回set容器的第一个迭代器                                    |
| s.end()                | 返回set容器的最后一个迭代器                                  |
| s.clear()              | 删除set容器中的所有的元素                                    |
| s.empty()              | 判断set容器是否为空                                          |
| s.max_size()           | 返回set容器可能包含的元素最大个数                            |
| s.size()               | 返回当前set容器中的元素个数                                  |
| s.rbegin()             | 返回的值和end()相同                                          |
| s.rend()               | 返回的值和rbegin()相同                                       |
| s.count()              | 用来查找set中某个某个键值出现的次数。这个函数在set并不是很实用，因为一个键值在set只可能出现0或1次，这样就变成了判断某一键值是否在set出现过了。 |
| s.equal_range()        | 返回一对定位器，分别表示第一个大于或等于给定关键值的元素和 第一个大于给定关键值的元素，这个返回值是一个pair类型，如果这一对定位器中哪个返回失败，就会等于end()的值。 |
| s.erase(iterator)      | 删除定位器iterator指向的值                                   |
| s.erase(first,second)  | 删除定位器first和second之间的值                              |
| s.erase(key_value)     | 删除键值key_value的值                                        |
| insert(key_value)      | 将key_value插入到set中 ，返回值是`pair<set<int>::iterator,bool>`，bool标志着插入是否成功，而iterator代表插入的位置，若key_value已经在set中，则iterator表示的key_value在set中的位置。 |
| inset(first,second)    | 将定位器first到second之间的元素插入到set中，返回值是void     |
| lower_bound(key_value) | 返回第一个大于等于key_value的定位器                          |
| upper_bound(key_value) | 返回最后一个大于等于key_value的定位器                        |