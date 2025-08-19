# 使用Git进行版本控制
## 向仓库中提交文件
### 1. 初始化仓库
```bash
git init
```
* 在当前目录创建一个新的 **Git 仓库**（会生成一个 `.git` 文件夹，里面保存版本信息）。
* 相当于告诉 Git，在这里开始版本控制。
### 2. 添加文件到暂存区
```bash
git add .
```
* 把当前目录下的所有文件（`.` 代表所有文件）添加到 **暂存区**。
* 暂存区就像一个“打包清单”，只有加进去的文件才会被提交。
### 3. 提交到本地仓库
```bash
git commit -m "first commit"
```
* 把暂存区里的文件正式提交到本地仓库，并加上说明信息 `"first commit"`。
* 这个信息可以帮助以后回顾代码历史。
### 4. 修改分支名
```bash
git branch -M main
```
* 把当前分支名改成 `main`。
### 5. 关联远程仓库
```bash
git remote add origin https://github.com/你的用户名/仓库名.git
```
* 给远程仓库取了个名字叫 `origin`，并把它的地址绑定上去。
* 这样 Git 就知道以后要往哪里推送代码。
### 6. 拉取远程分支到本地
```bash
git pull -u origin main --rebase
```
* `--rebase`的作用是把提交放到远程提交之后，保持历史干净。
* `-u` 参数表示以后可以直接用 `git push` 和 `git pull`，不用每次都写 `origin main`。
### 7. 推送到远程仓库
```bash
git push -u origin main
```
* 把本地 `main` 分支的代码推送到远程仓库 `origin`（GitHub）。
>可能会遇到类似 "Recv failure: Connection was reset" 或 "Failed to connect to http://github.com port 443 after 21114 ms: Couldn't connect to server" 的报错。即使打开了全局代理，也会报错。此时，需要为 Git 单独配置代理，可以使用以下命令（代理程序提供的端口，一种常见的情况是 7890）：
```bash
git config --global http.proxy http://127.0.0.1:7890
git config --global https.proxy http://127.0.0.1:7890
```
或者直接取消代理：
```bash
git config --global --unset http.proxy
git config --global --unset https.proxy
```
## 提交Pull Request
### 1. Fork 或在分支上开发
* 如果是 **自己仓库**：直接在 `main` 之外新建一个分支开发
  ```bash
  git checkout -b feature-branch
  ```
  修改并提交代码（使用`git add`与`git commit`），然后推送：
  ```bash
  git push origin feature-branch
  ```
* 如果是 **别人仓库**：需要先点 **Fork** 按钮，把别人的仓库复制到自己的 GitHub，然后在自己的仓库里新建分支修改，最后提交。
### 2. 去 GitHub 提交 Pull Request
1. 打开目标仓库的 GitHub 页面（如果是 fork，则打开 fork 的仓库）。
2. GitHub 通常会提示：
   **“Compare & pull request”**
   点击它。
3. 选择：
   * **base repository**（要合并到哪个仓库，通常是原始仓库的 main 分支）
   * **head repository**（你的分支所在仓库和分支）
4. 填写 PR 标题和描述，说明做了哪些改动。
5. 点击 **Create pull request**。
### 3. 等待审核与合并
* 仓库维护者会收到通知，查看你的修改。
* 如果需要修改，维护者可能会在 PR 下留言。
* 一旦审核通过，他们就会点击 **Merge**，你的代码就会被合并到主仓库。
