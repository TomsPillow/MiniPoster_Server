#include "def.h"
#include "fileopts.h"

int main(int argc, char* argv[])
{
    if(init_dir(argc, argv) == -1)
    {
        return -1;
    }

    if(init_network() == -1)
    {
        return -1;
    }

    while(1)
    {
        // 与客户端建立连接
        fprintf(stdout, "** waiting connect from clients...\n");
        struct sockaddr_in client_addr;
        memset(&client_addr, 0, sizeof(client_addr));
        socklen_t client_addr_len = sizeof(struct sockaddr_in);
        int connectfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
        fprintf(stdout, ">> accept Client IP:[%s], port[%d] **\n",inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        init_task();
        // 接收传输任务数据
        // task.filename
        read(connectfd, recvbuf, RECV_BUF_LEN);
        fprintf(stdout, ">> fetched target filename:[%s]\n", recvbuf);
        strcpy(task.filename, recvbuf);
        // task.total (byte)
        read(connectfd, recvbuf, RECV_BUF_LEN);
        unsigned int temp = 0;
        for(int i = 0 ; i < 4; i++)
        {
            temp = (unsigned char)recvbuf[i];
            // fprintf(stdout, "bytes[%d]=%d\n", i, temp);
            task.total = task.total + (temp << (i * 8));
        }
        fprintf(stdout, ">> file total bytes:[%dB]\n", task.total);

        // 检查当前目录下是否存在与目标文件名相同的文件
        if(check_file() == -1)
        {
            // 反馈错误信息
            write(connectfd, &vaild, sizeof(char));
            continue;
        }
        // 发送允许文件正常传输信号---enable_transfer
        write(connectfd, &vaild, sizeof(char));
        fprintf(stdout, "===> start file transfer task <===\n");
        while(task.current < task.total)
        {
            int len = read(connectfd, recvbuf, RECV_BUF_LEN);
            // fprintf(stdout, ">> recvbuf:%s  current:[%dB]  total:[%dB]\n", recvbuf, task.current, task.total);
            writeToFile(len);
            fprintf(stdout, ">> current:[%dB]  total:[%dB]\n", task.current, task.total);
            // 文件传输结束
            if(len == 0)
            {
                break;
            }
        }
        closeFile();
        close(connectfd);
    }
    close(sockfd);
    return 0;
}