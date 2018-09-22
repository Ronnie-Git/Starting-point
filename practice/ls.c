/*************************************************************************
	> File Name: k.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年09月22日 星期六 16时12分52秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h> 
#include <grp.h> 
#include <pwd.h> 
#include <time.h>
#include <string.h>
#include <dirent.h> 

int display_attr(const char *file) {
    struct stat buf;
    int ret;
    char *m;

    ret = lstat(file, &buf); // 判断获取文件信息是否成功
    if (ret == -1) {
        perror("lstat error");
        exit(0);
    }
    if (S_ISREG(buf.st_mode)) // 通过宏判断文件类型
        m = "-";
    else if (S_ISDIR(buf.st_mode))
        m = "d";
    else if (S_ISCHR(buf.st_mode))
        m = "c";
    else if (S_ISBLK(buf.st_mode))
        m = "b";
    else if (S_ISFIFO(buf.st_mode))
        m = "f";
    else if (S_ISLNK(buf.st_mode))
        m = "l";
    else if (S_ISSOCK(buf.st_mode))
        m = "s";
    else    
        m = "-";
    printf("%s", m);
    
    int n;
    int temp;
    int tmp;
    int flag = 0;
    for (n = 8; n >= 0; n--) {
        temp = 1 << n;
        tmp = buf.st_mode & temp;
        if (tmp) {
            switch (n % 3){
                case 2: printf("r"); break;
                case 1: printf("w"); break;
                case 0: printf("x"), flag = 1; break;
            }
        } else {
            printf("-");
        }
    }
    printf(" ");

    printf("%3d ", buf.st_nlink);

    struct passwd *pw = getpwuid(buf.st_uid); // uid
    printf("%8s ", pw -> pw_name);

    struct group *grp = getgrgid(buf.st_gid); // gid
    printf("%8s ", grp -> gr_name);

    printf("%5d ", (int)buf.st_size);

    struct tm *t;
    t = localtime(&(buf.st_mtime)); // 时间
    printf("%2d月 %02d %02d:%02d ", t -> tm_mon + 1, t -> tm_mday, t -> tm_hour, t -> tm_min);
    
    int color = *m; // 文件颜色 (部分文件颜色与ls -al相同)
    switch(color) {
        case 'd': printf("\033[;34;1m%s\033[0m", file); break;
        case 'l': printf("\033[;34;0m%s\033[0m", file); break;
        case 'b': printf("\033[;33;1m%s\033[0m", file); break;
        case '-': {
            if (flag) printf("\033[;32;1m%s\033[0m", file);
            else printf("%s", file);
            break;
        }
        default : printf("%s", file);
    }

    
    return 0;
}

int display(const char *path, int detail) {
    DIR *dir = NULL;
    struct dirent *de = NULL;
    int ret;
    
    dir = opendir(path);
    if (dir == NULL) {
        display_attr(path);
        printf("\n");
        return 0;
    } else {
        ret = chdir(path);
        if (ret != 0) {
            perror("error change dir");
            return -1;
        }
        while ((de=readdir(dir)) != NULL) {
            if (detail) {
                display_attr(de -> d_name);
                printf("\n");
            } else {
                printf("%s ", de -> d_name);
            }
        }
    }
    printf("\n");
    closedir(dir);

    return 0;
}

int main(int argc, char *argv[]) {
    // 判断是当前路径 还是输入的路径
    if (argc == 1) {
        display(".", 1); 
    } else if (argc == 2) {
        display(argv[1], 1); 
    } else {
        printf("Usage: %s [dir|file]\n", argv[0]);
        puts("Display file information of the dir you specify.\n");
        exit(0);
    }

    return 0;
}
