`fflush();`刷新缓冲区

https://www.cnblogs.com/uestc-mm/p/7630145.html



https://blog.csdn.net/hiluo302/article/details/75452058



https://www.cnblogs.com/rainbow1122/p/7852570.html



`bzero(&(server_addr.sin_zero), 8);`

`fd = socket(AF_TNET, SOCK_STREAM, 0);`

`bind(fd, (struct sockaddr *)&server_addr, struct_len) == -1);`

`accept(fd, (struct sockaddr *)&client_addr, &struct_len);`



`send(sockfd, buffer, strlen(buffer), 0);`

`recv(sockfd, buffer, BUFSIZ, 0)`



`pid_t pid;`

`pid = fork();`



`	FILE *fp = popen(shell, "r");`

`pclose(fp);`



`strncpy(str1, str2, strlen(str2));`

`sleep(5);`