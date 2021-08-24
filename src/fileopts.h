#include <sys/types.h>
#include <dirent.h>
#include "def.h"
#include <fcntl.h>
#include <sys/stat.h>

// 传输任务结构
struct Task
{
    int current;
    int total;
    char filename[MAX_FILE_NAME_LEN];
};
// 传输任务
struct Task task;
// 目录路径
char dirpath[MAX_DIR_PATH_LEN];
// 目标文件路径
char filepath[MAX_FILE_PATH_LEN];
// 目标文件状态指针
struct stat *st;
// 目标文件标识符
int fd;

int fetch_filepath();
int check_file();
int writeToFile(int len);
int closeFile();