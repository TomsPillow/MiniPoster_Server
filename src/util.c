#include "def.h"
#include "fileopts.h"

// 初始化目录信息
int init_dir(int argc, char* argv[])
{
    fprintf(stdout, "initializing directory info\n");
    // default mode
    if(argc == 1)
    {
        getcwd(dirpath, MAX_DIR_PATH_LEN);
    }
    // others
    else if(argc % 2 == 1)
    {
        for(int i = 1; i < argc; i = i + 2)
        {
            if(strcmp(argv[i + 1], "-p") == 0)
            {
                strcpy(dirpath, argv[i + 1]);
            }
        }
    }
    else
    {
        fprintf(stdout, "wrong argument number\n");
    }

    if(opendir(dirpath) == NULL)
    {
        fprintf(stdout, "wrong directory path:[%s], please check it out\n", dirpath);
        return -1;
    }
    fprintf(stdout, ">> working in directory:[%s]\n", dirpath);
    return 0;
}

// 初始化网络信息
int init_network()
{
    fprintf(stdout, "initializing network info\n");
    // 采用IPv4协议，TCP数据流套接字
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1)
    {
        fprintf(stdout, "the setup of socket failed\n");
        return -1;
    }
    fprintf(stdout, ">> socket established\n");
    
    // 指定套接字接收地址，端口，协议簇
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(DEFAULT_PORT);

    // 绑定地址结构信息
    int fd = bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if(fd == -1)
    {
        fprintf(stdout, "port[%d] bind failed\n", DEFAULT_PORT);
        return -1;
    }
    fprintf(stdout, ">> port[%d] bind\n", DEFAULT_PORT);
    // 监听端口
    fd = listen(sockfd, MAX_LISTEN_QUEUE);
    if(fd == -1)
    {
        fprintf(stdout, "listen failed\n");
        return -1;
    }
    fprintf(stdout, ">> start listening...\n");
    return 0;
}