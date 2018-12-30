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
#include <sys/stat.h> /* stat */
#include <grp.h> /* getgrgid() */
#include <pwd.h> /* passwd, getpwuid(), etc */
#include <time.h>
#include <string.h>
#include <dirent.h> /* opendir(), etc */

static int get_file_name(char *file, const char *path) {
    if (file == NULL || path == NULL) {
        printf("Error: do you forget malloc??\n");
        return -1;
    }

    int len = strlen(path);
    int pos = len - 1;

    while (pos >= 0 && path[pos] != '/') pos--;

    strcpy(file, path + pos + 1);

    return 0;
}

static int display_file_name(const char *path) {
    int len = 0;
    char *file = NULL;

    len = strlen(path);
    file = (char *)malloc(len+1);

    get_file_name(file, path);
    printf("%s ", file);
    free(file);
    
    return 0;
}

static int display_attr(const char *file) {
    struct stat buf;
    int ret;
    char *m;    /* OK here */

    ret = lstat(file, &buf);
    if (ret == -1) {
        perror("lstat error");
        //return -1;
        exit(0);
    }
    /**
     * file mode
     * st_mode sample(in oct):
     * 0   12   0  7     4     4
     *     l       rwx   rw-    rw-
     * oct type ?? owner group others
     * see man page for details($man lstat)
     */
    if (S_ISREG(buf.st_mode))
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
    else    /* just kidding */
        m = "-";
    printf("%s", m);
    
    /*file permission*/
    int n;
    int temp;
    int tmp;
    for (n = 8; n >= 0; n--) {
        /**
         * temp:
         * dec 256  128  64   32   16   8    4    2    1
         * oct 0400 0200 0100 0040 0020 0010 0004 0002 0001
         */
        temp = 1<<n;
        tmp = buf.st_mode & temp;
        if (tmp) {
        // if (buf.st_mode & (1<<n))
            switch (n%3){
                case 2: printf("r"); break;
                case 1: printf("w"); break;
                case 0: printf("x"); break;
            }
        } else {
            printf("-");
        }
    }
    printf(" ");

    /* number of hard link */
    printf("%3d ", buf.st_nlink);

    /* user name */
    struct passwd *pw = getpwuid(buf.st_uid);
    printf("%8s ", pw -> pw_name);

    /* group name */
    struct group *grp = getgrgid(buf.st_gid);
    printf("%8s ", grp -> gr_name);

    /* file size */
    printf("%5d ", (int)buf.st_size);

    /* last modify time */
    struct tm *t;
    t = localtime(&(buf.st_mtime));
    printf("%4d-%02d-%02d %02d:%02d ", t -> tm_year + 1900, t -> tm_mon + 1,
           t -> tm_mday, t -> tm_hour, t -> tm_min);

    /* file name... */
    printf("%s", file);
    return 0;
}
int display(const char *path, int detail) {
    DIR *dir = NULL;
    struct dirent *de = NULL;
    int ret;
    
    dir = opendir(path);
    if (dir == NULL) {
        /**
         * Note: This is not actualy an error!!
         * We show the file, but if it does not exist, we will handle it.
         */
        display_attr(path);
        //display_file_name(path);
        //printf("%s", path);
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
                display_attr(de->d_name);
                //display_file_name(de->d_name);
                //printf("%s ", de->d_name);
                printf("\n");
            } else {
                //display_file_name(de->d_name);
                printf("%s ", de->d_name);
            }
        }
    }
    printf("\n");
    closedir(dir);

    return 0;
}
int main(int argc, char *argv[]) {
    if (argc == 1) {
        display(".", 1); /* current dir */
    } else if (argc == 2) {
        display(argv[1], 1); /* the dir you specify */
    } else {
        printf("Usage: %s [dir|file]\n", argv[0]);
        puts("Display file information of the dir you specify.\n");
        exit(0);
    }

    return 0;
}
