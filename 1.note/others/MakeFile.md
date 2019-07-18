### MakeFile

```makefile
CXX := g++
CFLAGS := -Wall -g
OBJS = main.o arr.o

a.out: $(OBJS)
	@$(CXX) -o $@ $(CFLAGS) $(OBJS)

$(OBJS) : %.o: %.cpp
	@$(CXX) -c $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	@rm -f *.o a.out
	@echo Done cleaning
```



**`-g `可执行程序包含调试信息**

加个`-g` 是为了`gdb`用，不然`gdb`用不到



**`-o` 指定输出文件名**

上面的意思是如果你不打 -o filename 那么默认就是输出filemame.out.这个-o就是用来控制输出文件的。



**`-c` 只编译不链接**

生成`.o`链接文件， 也叫目标文件



### 常用

`$#` 是传给脚本的参数个数

`$0` 是脚本本身的名字

`$1` 是传递给该shell脚本的第一个参数

`$2` 是传递给该shell脚本的第二个参数
`$@` 是传给脚本的所有参数的列表，代表目标文件(target) 
`$*` 是以一个单字符串显示所有向脚本传递的参数，与位置变量不同，参数可超过9个
`$$` 是脚本运行的当前进程ID号
`$?` 是显示最后命令的退出状态，0表示没有错误，其他表示有错误
`@`这个符串通常用在“规则”行中，表示不显示命令本身，而只显示它的结果
 `$^`代表所有的依赖文件(components)



`$@`  表示目标文件
`$^`  表示所有的依赖文件
`$<`  表示第一个依赖文件
`$?`  表示比目标还要新的依赖文件列表



#### 区别：`$@` `$*`

- 相同点：都是引用所有参数
- 不同点：只有在双引号中体现出来。假设在脚本运行时写了三个参数（分别存储在`$1` `$2` `$3`）则"`$*`" 等价于 “`$1` `$2` `$3`"（传递了一个参数）；而`$@` 等价于 "`$1`" "`$2`" "`$3`"（传递了三个参数）



#### `$@`、`$^`、`$<`用法比较：

```makefile
main.out:main.o line1.o line2.o
	g++ -o $@ $^
main.o:main.c line1.h line2.h
	g++ -c $<
line1.o:line1.c line1.h
	g++ -c $<
line2.o:line2.c line2.h
	g++ -c $<
```



#### `$<`   `$@`

静态模式可以更加容易地定义多目标的规则，可以让我们的规则变得更加的有弹性和灵活。我们还是先来看一下语法：

```makefile
<targets ...>: <target-pattern>: <prereq-patterns ...>
　　<commands>
...
```



如果我们的`<target-parrtern>`定义成“`%.o`”，意思是我们的`<target>`集合中都是以“`.o`”结尾的，而如果我们的`<prereq-parrterns>`定义成“`%.c`”，意思是对`<target-parrtern>`所形成的目标集进行二次定义，其计算方法是，取`<target-parrtern>`模式中的“`%`”（也就是去掉了[`.o`]这个结尾），并为其加上[`.c`]这个结尾，形成的新集合。所以，我们的“目标模式”或是“依赖模式”中都应该有“`%`”这个字符。



```makefile
objects = foo.o bar.o
all: $(objects)
$(objects): %.o: %.c
$(CC) -c $(CFLAGS) $< -o $@
```

上面的例子中，指明了我们的目标从`$objects`中获取，“`%.o`”表明要所有以“`.o`”结尾的目标，也就是“`foo.o bar.o`”，也就是变量`$object`集合的模式，而依赖模式“`%.c`”则取模式“`%.o`”的“`%`”，也就是“`foo bar`”，并为其加下“`.c`”的后缀，于是，我们的依赖目标就是“`foo.c bar.c`”。而命令中的“`$<`”和“`$@`”则是自动化变量，“`$<`”表示所有的依赖目标集（也就是“`foo.c bar.c`”），“`$@`”表示目标集（也就是“`foo.o bar.o`”）。于是，上面的规则展开后等价于下面的规则：

```makefile
foo.o : foo.c
$(CC) -c $(CFLAGS) foo.c -o foo.o
bar.o : bar.c
$(CC) -c $(CFLAGS) bar.c -o bar.o
```

