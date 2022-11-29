**服务器添加公钥：**
在服务器上运行：ssh-keygen
一路回车；
找到上面显示的vim /home/qing.xiang/.ssh/id_rsa.pub
把里面的东西复制到服务器添加公钥的位置。

# 修改用户名和邮箱
git config user.name 你的目标用户名;
git config user.email 你的目标邮箱名;
如果你要修改当前全局的用户名和邮箱时，需要在上面的两条命令中添加一个参数，--global，代表的是全局。命令分别为：
git config  --global user.name 你的目标用户名；
git config  --global user.email 你的目标邮箱名;

# 提交到gerrit
git push origin HEAD:refs/for/[分支名]

# gerrit被退回：
git add 修改后的文件
git commit --amend
ctrl + x
git push origin HEAD:refs/for/master

# pull
+ 将远程指定分支 拉取到 本地指定分支上：
git pull origin <远程分支名>:<本地分支名>
+ 将远程指定分支 拉取到 本地当前分支上：
git pull origin <远程分支名>
+ 将与本地当前分支同名的远程分支 拉取到 本地当前分支上(需先关联远程分支，方法见文章末尾)
git pull

在克隆远程项目的时候，本地分支会自动与远程仓库建立追踪关系，可以使用默认的origin来替代远程仓库名，
所以，我常用的命令就是 git pull origin <远程仓库名>，操作简单，安全可控。

# push
+ 将本地当前分支 推送到 远程指定分支上（注意：pull是远程在前本地在后，push相反）：
git push origin <本地分支名>:<远程分支名>
+ 将本地当前分支 推送到 与本地当前分支同名的远程分支上（注意：pull是远程在前本地在后，push相反）：
git push origin <本地分支名>

# 关联远程分支
git push --set-upstream origin/<远程分支名> <本地分支名>

# 新建 和 删除 分支
git branch <分支名>
git branch -d <分支名>

# 扔掉stash
git stash drop stash@{0}