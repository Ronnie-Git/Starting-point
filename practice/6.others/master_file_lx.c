/*************************************************************************
	> File Name: k.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年09月23日 星期日 16时36分46秒
 ************************************************************************/

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
#include "common.h"

int func(int, int, char *, int);

int main(int argc, char *argv[]) {
    int fd, new_fd, struct_len, numbytes;
    int cnt = 0, op = 0;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    char buff[BUFSIZ]; // 缓冲区
    char server_port[100];

    int g = get("common.conf", "port", server_port);

    server_addr.sin_family = AF_INET; // IP地址
    server_addr.sin_port = htons(atoi(server_port)); // 端口
    server_addr.sin_addr.s_addr = INADDR_ANY;
    bzero(&(server_addr.sin_zero), 8); // 地址族协议
    struct_len = sizeof(struct sockaddr_in);

    fd = socket(AF_INET, SOCK_STREAM, 0); // socket
    while(bind(fd, (struct sockaddr *)&server_addr, struct_len) == -1); // bind 绑定
    printf("绑定成功\n");
    while(listen(fd, 10) == -1); // 进入监听状态
    printf("正在监听中......\n");
    int connect;
    pid_t pid;
    while(1) {
        connect = accept(fd, (struct sockaddr *)&client_addr, &struct_len); // 接收客户请求
        printf("出现访客\n");
        cnt++;
        char IP[100];
        int port;
        strcpy(IP, inet_ntoa(client_addr.sin_addr)); 
        port = htons(client_addr.sin_port);
        func(connect, cnt, IP, port);
        numbytes = send(new_fd, "欢迎,祝您愉快!\n", 21, 0);
        if (op == 5) continue;
        op++;
        pid = fork();
        if (pid == -1) {
            printf("fork出错\n");
        } else if (pid == 0) {
            close(fd);
            char IP[100];
            int port;
            char f[10] = {0};
            switch (op) {
                case 1: strcpy(f, "f1"); break;
                case 2: strcpy(f, "f2"); break;
                case 3: strcpy(f, "f3"); break;
                case 4: strcpy(f, "f4"); break;
                case 5: strcpy(f, "f5"); break;
            }
            int i = 0;
            while (i < 2) {
                FILE *F = fopen(f, "r");
                char *str;
                size_t len = 0;
                //fread(str, sizeof(char), strlen(str), F);
                for (int j = 0; j <= i; j++) {
                    getline(&str, &len, F);
                }
                //int k = atoi(str);
                //strcpy(IP, inet_ntoa(client_addr.sin_addr)); 
                //port = htons(client_addr.sin_port);
                while((numbytes = recv(connect, buff, BUFSIZ, 0)) > 0) { // 接收数据
                    sleep(2);
                }
                //printf("访客\"%s %d\"退出\n", IP, port);
                printf("访客\"%s\"退出\n", str);
                fclose(F);
                i++;
            }
            exit(EXIT_SUCCESS);
        } else {
            close(connect);
        }
    }
    return 0;
}

int func(int connect, int cnt, char *IP, int port) {
    char f[100] = {0};
    switch (cnt % 5) {
        case 0: strcpy(f, "f5"); break;
        case 1: strcpy(f, "f1"); break;
        case 2: strcpy(f, "f2"); break;
        case 3: strcpy(f, "f3"); break;
        case 4: strcpy(f, "f4"); break;
    }
    FILE *F;
    char data[500] = {0};
    F = fopen(f, "a+");
    int k = port, i = 1;
    data[0] = ':';
    while (k) {
        data[i++] = k % 10 + '0';
        k /= 10;
    }
    data[i] = '\n';
    fwrite(IP, sizeof(char), strlen(IP), F);
    fwrite(data, sizeof(char), strlen(data), F);
    fclose(F);
    return 0;
}
