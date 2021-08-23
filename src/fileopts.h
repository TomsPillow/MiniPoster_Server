#include <sys/types.h>
#include <dirent.h>
#include "def.h"
// 目录路径
static char dirpath[MAX_DIR_PATH_LEN];
// 目标文件名
static char filename[MAX_FILE_NAME_LEN];
// 目标文件指针
static FILE *fp;