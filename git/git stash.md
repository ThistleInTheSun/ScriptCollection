# Name
git-stash - 将更改存储在脏工作目录中

# synopsis(概要)
```sh
git stash list [<options>]
git stash show [<stash>]
git stash drop [-q|--quiet] [<stash>]
git stash ( pop | apply ) [--index] [-q|--quiet] [<stash>]
git stash branch <branchname> [<stash>]
git stash [push [-p|--patch] [-k|--[no-]keep-index] [-q|--quiet]
            [-u|--include-untracked] [-a|--all] [-m|--message <消息>]
            [--] [<pathspec>...]]
git stash clear
git stash create [<message>]
git stash store [-m|--message <message>] [-q|--quiet] <commit>
```
# description
当你想记录工作目录和索引的当前状态，但又想回到一个干净的工作目录时，使用 git stash。该命令保存您的本地修改并将工作目录恢复为匹配 HEAD 提交。

可以使用 git stash list 列出通过此命令隐藏的修改，使用 git stash show 检查，并使用 git stash apply 恢复（可能在不同的提交之上）。 调用不带任何参数的 git stash 等同于 git stash push。 默认情况下，存储被列为“WIP on branchname ...”，但您可以在创建存储时在命令行上提供更具描述性的消息。

您创建的最新存储存储在 refs/stash 中； 较旧的存储可以在该引用的引用日志中找到，并且可以使用通常的引用日志语法命名（例如，stash@{0} 是最近创建的存储，stash@{1} 是它之前的存储，stash@{2.hours .ago} 也是可能的）。 也可以通过仅指定存储索引来引用存储（例如，整数 n 等同于 stash@{n}）。

# options
```push [-p|--patch] [-k|--[no-]keep-index] [-u|--include-untracked] [-a|--all] [-q|--quiet] [-m|--message <message>] [--] [<pathspec>...]```
+ 将您的本地修改保存到新的存储条目并将它们回滚到 HEAD（在工作树和索引中）。 <message> 部分是可选的，并提供描述和隐藏状态。

+ 为了快速制作快照，您可以省略“push”。在这种模式下，不允许使用非选项参数来防止拼写错误的子命令产生不需要的存储条目。这两个例外是 stash -p，它充当 stash push -p 和 pathspecs 的别名，允许在双连字符后使用 -- 以消除歧义。

+ 当给 git stash push 指定 pathspec 时，新的 stash 条目只记录与 pathspec 匹配的文件的修改状态。索引条目和工作树文件然后回滚到 HEAD 中的状态，只为这些
文件，也保留与路径规范不匹配的文件。

+ 如果使用 --keep-index 选项，所有已添加到索引的更改将保持不变。

+ 如果使用 --include-untracked 选项，所有未跟踪的文件也会被隐藏，然后用 git clean 清理，使工作目录处于非常干净的状态。 如果使用 --all 选项，那么除了未跟踪的文件之外，忽略的文件也会被隐藏和清理。

+ 使用 --patch，您可以交互地从 HEAD 和要隐藏的工作树之间的差异中选择块。 存储条目的构造使其索引状态与存储库的索引状态相同，并且其工作树仅包含您以交互方式选择的更改。 然后从您的工作树中回滚选定的更改。 请参阅 git-add(1) 的“交互模式”部分以了解如何操作 --patc

+ --patch 选项意味着 --keep-index。您可以使用 --no-keep-index 来覆盖它。

```save [-p|--patch] [-k|--[no-]keep-index] [-u|--include-untracked] [-a|--all] [-q|--quiet] [<message>]```
+ 此选项已弃用，取而代之的是 git stash push。它与“隐藏推送”的不同之处在于它不能采用路径规范，并且任何非选项参数都构成消息。

```list [<options>]```
+ 列出您当前拥有的存储条目。每个存储条目都列出了它的名称（例如，stash@{0} 是最新的条目，stash@{1} 是之前的条目，等等），创建条目时当前分支的名称，以及条目所基于的提交的简短描述。

        stash@{0}：提交时在制品：6ebd0e2 ...更新 git-stash 文档
        stash@{1}: 在 master: 9cc0589... 添加 git-stash

+ 该命令采用适用于 git log 命令的选项来控制显示的内容和方式。请参阅 git-log(1)。

```show [<stash>]```
+ 将存储条目中记录的更改显示为存储内容与首次创建存储条目时的提交之间的差异。 当没有给出 <stash> 时，它显示最新的。 默认情况下，该命令显示 diffstat，但它会接受 git diff 已知的任何格式（例如， git stash show -p stash@{1} 以补丁形式查看第二个最近的条目）。 您可以使用 stash.showStat 和/或 stash.showPatch 配置变量来更改默认行为。