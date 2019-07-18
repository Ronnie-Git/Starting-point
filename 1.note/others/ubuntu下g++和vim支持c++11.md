## ubuntu 下 g++ 和 vim 支持 c++11

### g++ 支持 c++11

```shell
sudo vim ~/.bashrc # 在 .bashrc 文件中添加下面一行代码
alias g++='g++ -std=c++11'
```



### vim 支持 c++11

```shell
vim .vimrc # 在 .vimrc 文件中添加下面一行代码
let g:syntastic_cpp_compiler_options = ' -std=c++11 -stdlib=libc++'
```

