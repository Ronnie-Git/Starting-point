/*************************************************************************
	> File Name: common.h
	> Author: 
	> Mail: 
	> Created Time: Thu 25 Apr 2019 08:36:24 UTC
 ************************************************************************/

#ifndef _COMMON_H
#define _COMMON_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "info.h"

#define MAXSIZE 100

void get_cmd(char *command, char cmd[][MAXSIZE]);
void run_cmd(char *command, char cmd[][MAXSIZE]);

#endif
