/*************************************************************************
	> File Name: operation.h
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月01日 星期二 18时43分20秒
 ************************************************************************/

#ifndef _OPERATION_H
#define _OPERATION_H

class Operation {
private :
    char key;
    int value1;
    int value2;
public :
    int getValue(int x, int y);
    int getKey(char c);
    int ans();
};

#endif
