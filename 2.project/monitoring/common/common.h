/*************************************************************************
	> File Name: common.h
	> Author: x
	> Mail: x.com
	> Created Time: 2018年12月06日 星期四 19时45分38秒
 ************************************************************************/

#ifndef _COMMON_H
#define _COMMON_H

#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/wait.h>

int get(char *filename, char *name, char *v) {
    FILE *fd = fopen(filename, "r");
    size_t len = 0;
    ssize_t read;
    char *line = NULL;
    while ((read = getline(&line, &len, fd)) != -1) {
        char *str = strstr(line, name);
        if(str) {
            char *str2 = strstr(line, "=");
            if (!str2) continue;
            strncpy(v, line + strlen(name) + 1, strlen(line) - strlen(name) - 2); // 换行符 等于号
            fclose(fd);
            return 1;
        }
    }
    free(line);
    fclose(fd);
    return 0;
}

int soc_con(char *IP, int port) {

    struct sockaddr_in server_addr;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0); // 创建一个socket
    if (sockfd < 0) return -1;
    server_addr.sin_family = AF_INET; // 初始化服务器地址
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(IP);
    bzero(&(server_addr.sin_zero), 8);
    
    int k = connect(sockfd, (struct sockaddr*)&server_addr, sizeof(struct sockaddr));
    if (k < 0) return -1;
    return sockfd;
}

int get_IP(char *filename, int cnt, char *v) {
    FILE *fd = fopen(filename, "r");
    size_t len = 0;
    ssize_t read;
    char *line = NULL;
    int i = 0;
    while ((read = getline(&line, &len, fd)) != -1) {
        if (i == cnt) {
            strncpy(v, line, strlen(line) - 1);
        }
        i++;
    }
    free(line);
    fclose(fd);
    return 0;
}

#endif
