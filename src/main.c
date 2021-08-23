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
        fprintf(stdout, "waiting connect from clients...\n");
        struct sockaddr_in client_addr;
        memset(&client_addr, 0, sizeof(client_addr));
        socklen_t client_addr_len = 0;
        // 与客户端建立连接
        int connectfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
        fprintf(stdout, "** accept Client IP:[%s], port[%d] **",inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        
        while((recvbuf_len = read(connectfd, recvbuf, RECV_BUF_LEN)) != 0)
        {
            fprintf(stdout, "%s", recvbuf);
        }
        close(connectfd);
    }
    close(sockfd);
    return 0;
}