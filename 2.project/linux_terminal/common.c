/*************************************************************************
	> File Name: common.c
	> Author: 
	> Mail: 
	> Created Time: Thu 25 Apr 2019 09:06:59 UTC
 ************************************************************************/

#include "./common/common.h"

// 从输入的内容中提取命令和参数
void get_cmd(char *command, char cmd[][MAXSIZE]) {
	for (int i = 0; ; i++) {
        // 空格前面的是命令，后面的是参数
        // 如果没有空格，那么将整个字符串都当作命令
        if (command[i] == ' ' || command[i] == '\0') {
            strncpy(cmd[0], command, i);
            cmd[0][i] = '\0';
            strncpy(cmd[1], command + i + 1, MAXSIZE - i - 1);
            break;
        }
	}
    return ;
}

// 运行命令
void run_cmd(char *command, char cmd[][MAXSIZE]) {
    // 命令为 exit 时，结束程序
    if (strncmp(command, "exit", 4) == 0) exit(0);
    // cd 命令通过 chdir() 函数实现，其余命令通过 system()
    if (strncmp(cmd[0], "cd", 2) == 0) {
   	    if (chdir(cmd[1]) == -1) {
   		    perror("chdir");
   	    }
    } else {
        system(command);
    }
    return ;
}
