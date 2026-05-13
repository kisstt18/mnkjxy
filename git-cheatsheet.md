# Git 常用命令速查

## 一、基础配置（一次性）

| 命令 | 说明 |
|------|------|
| `git config --global user.name "你的名字"` | 设置用户名 |
| `git config --global user.email "你的邮箱"` | 设置邮箱 |

## 二、日常高频（每天用）

| 命令 | 说明 |
|------|------|
| `git status` | 查看当前状态（改了哪些文件） |
| `git add 文件名` | 暂存指定文件 |
| `git commit -m "提交信息"` | 提交暂存的文件 |
| `git push` | 推送到 GitHub |
| `git pull` | 从 GitHub 拉取最新代码 |

## 三、撤销操作

| 命令 | 说明 |
|------|------|
| `git reset HEAD 文件名` | 取消暂存（add 的反操作） |
| `git checkout -- 文件名` | 撤销文件的修改（回到上次 commit 的状态） |
| `git reset --soft HEAD~1` | 撤销最近一次 commit（改动保留） |

## 四、文件操作

| 命令 | 说明 |
|------|------|
| `git rm 文件名` | 删除文件（同时从磁盘和 Git 移除） |
| `git mv 旧名 新名` | 重命名/移动文件 |

## 五、查看历史

| 命令 | 说明 |
|------|------|
| `git log` | 查看提交历史 |
| `git log --oneline` | 简洁版提交历史 |
| `git diff` | 查看具体改了什么 |

## 六、分支（后面学）

| 命令 | 说明 |
|------|------|
| `git branch` | 查看所有分支 |
| `git branch 分支名` | 创建新分支 |
| `git checkout 分支名` | 切换到指定分支 |
| `git merge 分支名` | 合并分支 |

## 七、日常工作流

```bash
# 1. 写代码
# 2. 看一下改了啥
git status

# 3. 一个一个加
git add day01_bmi.py

# 4. 提交
git commit -m "feat: 完成BMI计算器"

# 5. 推到 GitHub
git push

# 6. 关电脑前再看一眼
git status
```
