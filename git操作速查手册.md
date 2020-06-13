# git操作速查手册

## 从工作区add文件到暂存区
+ git add filename1 filename2 从工作区添加一个文件或者多个文件到暂存区

## 从暂存区commit文件到本地仓库
+ git commit
 + git要求commit的时候添加一段说明，如果不添加则无法commit（也可以强制commit）

## 将本地仓库的内容合并到远程仓库
+ git push # 将本地仓库的内容合并到远程仓库
    + git push -f master #用本地的仓库强制覆盖远程仓库（慎用！） 

## 将远程仓库的内容同步到本地仓库 
+ git pull 

## 创建分支
+ git branch branch_name

## 切换分支
+ git checkout branch_name
    + 在切换分支之前需要将当前暂存区文件commit到本地仓库，否则无法切换

 

