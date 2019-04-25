/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: Thu 25 Apr 2019 08:34:18 UTC
 ************************************************************************/

#include "./common/common.h"

int main() {
	while (1) {
		info_print();
		char command[MAXSIZE] = {0}, cmd[2][MAXSIZE] = {0};
        scanf("%[^\n]s", command);
        getchar();

        get_cmd(command, cmd);
        run_cmd(command, cmd);
	}
	return 0;
}
