/*************************************************************************
	> File Name: info.c
	> Author: 
	> Mail: 
	> Created Time: Thu 25 Apr 2019 08:34:56 UTC
 ************************************************************************/

#include "./common/common.h"

// 获取用户名、主机名、当前路径
// 配色
void info_print() {
	char *username, hostname[MAXSIZE] = {0}, pwd[MAXSIZE] = {0};
    char color[MAXSIZE] = "\033[;32m\033[1m%s@%s\033[0m:\033[;34m\033[1m%s $\033[0m ";
	if ((username = getenv("USER")) == NULL) {
		printf("Error: get username failure!\n");
		exit(-1);
	}
	if (getcwd(pwd, MAXSIZE) == NULL) {
		perror("getcwd");
		exit(-1);
	}
	if (gethostname(hostname, MAXSIZE) == -1) {
		perror("gethostname");
		exit(-1);
	}
	if (strcmp(username,"root") == 0) {
	    printf("%s@%s:%s# ", username, hostname, pwd);
	} else {
	    printf(color, username, hostname, pwd);
	}
    return ;
}

