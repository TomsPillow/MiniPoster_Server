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

static char recvbuf[RECV_BUF_LEN];
static unsigned int recvbuf_len;

static int sockfd;
static struct sockaddr_in server_addr;

// util.c
int init_dir(int argc, char* argv[]);
int init_network();