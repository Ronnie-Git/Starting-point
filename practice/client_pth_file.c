/*************************************************************************
	> File Name: k.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年09月23日 星期日 16时36分46秒
 ************************************************************************/

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

void func(char *str, char *m, int sockfd) {
    char buf[BUFSIZ] = {0};
    char data[1000] = {0};
	FILE *fp = popen(m, "r");
    fread(data, sizeof(char), sizeof(data), fp);
    buf[0] = strlen(str) + '0';
    strncpy(buf + 1, str, strlen(str));
    strncpy(buf + 1 + strlen(str), data, strlen(data));
    while (send(sockfd, buf, strlen(buf), 0) < -1);
    pclose(fp);
    return ;
}

void *soc_func(void *argv) {
    struct sockaddr_in server;
    server.sin_family = AF_INET; // 初始化服务器地址
    server.sin_port = htons(8000);
    server.sin_addr.s_addr = inet_addr("192.168.2.174");
    bzero(&(server.sin_zero), 8);
    int fd;
    while ((fd = socket(AF_INET, SOCK_STREAM, 0)) == -1); // socket
    while (1) {
	    while (connect(fd, (struct sockaddr*)&server, sizeof(struct sockaddr)) == -1);
        if (fd != -1) close(fd);
        printf("cds\n");
        sleep(5);
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("./Client 地址 端口\n");
        exit(1);
    }
    int port = atoi(argv[2]); // int型 端口
    char *host = argv[1]; // 地址
    int fd, new_fd, struct_len, numbytes, i;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    char buff[BUFSIZ]; // 缓冲区

    server_addr.sin_family = AF_INET; // IP地址
    server_addr.sin_port = htons(8725); // 端口
    server_addr.sin_addr.s_addr = INADDR_ANY;
    bzero(&(server_addr.sin_zero), 8); // 地址族协议
    struct_len = sizeof(struct sockaddr_in);
    
    struct sockaddr_in *ser = &server_addr;
    pthread_t t;
    pthread_create(&t, NULL, soc_func, NULL);

    fd = socket(AF_INET, SOCK_STREAM, 0); // socket
    while(bind(fd, (struct sockaddr *)&server_addr, struct_len) == -1); // bind 绑定
    printf("绑定成功\n");
    while(listen(fd, 10) == -1); // 进入监听状态
    printf("正在监听中......\n");
    new_fd = accept(fd, (struct sockaddr *)&client_addr, &struct_len);
    while(1) {
        func("cpu.log", "./cpulog.sh", new_fd);
        sleep(1);
        func("mem.log", "./memlog.sh", new_fd);
        func("disk.log", "./Disk_information.sh", new_fd);
        sleep(5);
    }
    return 0;
}
