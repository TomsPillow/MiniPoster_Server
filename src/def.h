#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#define DEFAULT_PORT 3333
#define MAX_LISTEN_QUEUE 10
#define RECV_BUF_LEN 1024
#define MAX_DIR_PATH_LEN 1024
#define MAX_FILE_NAME_LEN 1024
#define MAX_FILE_PATH_LEN 1024

char recvbuf[RECV_BUF_LEN];
unsigned int recvbuf_len;

int sockfd;
struct sockaddr_in server_addr;
char vaild;
// util.c
int init_dir(int argc, char* argv[]);
int init_network();
int init_task();