/*************************************************************************
	> File Name: a.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年09月30日 星期日 10时55分11秒
 ************************************************************************/


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
