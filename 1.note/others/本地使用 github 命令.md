# 本地使用 github 命令

`git status` 查看状态

`git add` 文件名  交给管理

`git commit -m ""`  交给管理

`git push` 提交

`git pull` 更新同步本地和github

`git log` 查看历史提交状态

`git reset --hard ID号` 退回到某个版本命令

`git --help` 帮助命令

`git pull origin master` 将远程仓库里面的项目拉下来

`dir` 查看有哪些文件夹

## 删除文件夹或文件

`git rm -r --cached 文件或文件夹名`  删除文件或文件夹

`git commit -m "说明"` 提交,添加操作说明

`git push -u origin master` 将本次更改更新到github项目上去

# 实现本地免密登录github

将本机的公匙添加到github

`mkdir 文件名` 建立一个文件存放仓库（可以不执行该命令）

`git init` 生成 .git 文件夹（可以不执行该命令）

`git config --global user.name "自己的用户名"`

`git config --global user.email "自己的邮箱"`

在本机建立一个文件夹将github资料库拷贝过来`git clone 自己的仓库链接`