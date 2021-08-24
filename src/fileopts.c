#include "fileopts.h"

int fetch_filepath()
{
    strcat(filepath, dirpath);
    if(filepath[strlen(filepath) - 1] !='/')
    {
        strcat(filepath, "/");
    }
    strcat(filepath, task.filename);
    return 0;
}

int check_file()
{
    fetch_filepath();
    st = (struct stat *)malloc(sizeof(struct stat));
    // 目录下的文件不存在
    if(stat(filepath, st) != 0)
    {
        if((fd = open(filepath, O_WRONLY | O_CREAT, 0007)) != -1)
        {
            fprintf(stdout, ">> target file was created successfully\n");
            vaild = 1;
            return 0;
        }
        vaild = 2;
        fprintf(stdout, "failed to create target file\n");
        closeFile();
        return -1;
    }
    vaild = 3;
    fprintf(stdout, "the file has existd\n");
    return -1;
}

int writeToFile(int len)
{
    // memset(recvbuf, 0, RECV_BUF_LEN);
    task.current = task.current + write(fd, recvbuf, len);
    return 0;
}

int closeFile()
{
    return close(fd);
}