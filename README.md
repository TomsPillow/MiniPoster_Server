# MiniPoster_Server
## 项目介绍
* MiniPoster_Server为服务器端程序
* 实现本地主机到个人服务器的文件单向传输
* 面向 Linux系统编写
## 使用步骤
* 终端输入`git clone https://github.com/samona-omo/MiniPoster_Server.git`
* 完成下载后，进入`MinPoster_Server`目录，输入`sh complier.sh`
* 编译结束，输入`sh run.sh`，启动服务程序
* 在本地主机使用[MiniPoster_Client](https://github.com/samona-omo/MiniPoster_Client)程序进行目标文件传输
## 关于启动文件`run.sh`的说明
* 初始命令为`./bin/server -p ../`，其中`-p`指定文件上传目录，
* 这里设置为了`MiniPoster_Server`的上层目录，如有需要，可自行更改。
# 不排除bug存在的可能性，>_<
