/*************************************************************************
	> File Name: check.h
	> Author: x
	> Mail: x.com
	> Created Time: 2018年12月07日 星期五 18时04分09秒
 ************************************************************************/

#ifndef _CHECK_H
#define _CHECK_H

int check_size(char *filename, int size, char *dir) {
    struct stat st;
    int flag;
    char cmd_1[50] = {0};
    char cmd[100] = {0};
    char basename[10] = {0};
    time_t _time;
    struct tm *lt;
    stat(filename, &st);
    int size_real = st.st_size / 1048576;
    /*if (size_real >= size) {
        flag = 0;
    } else {
        return 0;
    }*/

    sprintf(cmd_1, "basename %s", filename);
    FILE *stream = popen(cmd_1, "r");

    fgets(basename, sizeof(basename), stream);
    
    printf("%s\n", basename);
    time(&_time);
    lt = localtime(&_time);
    
    sprintf(cmd, "cp -a %s %s/%s_35", filename, dir, basename);
    system(cmd);
    return 0;
}

#endif
