/*************************************************************************
	> File Name: Arr.h
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月01日 星期二 20时15分27秒
 ************************************************************************/

#ifndef _ARR_H
#define _ARR_H

#define MAX_N 20

class Arr {
private :
    int *data;
    int length;
public :
    Arr();
    int getLength();
    int getValue(int ind, int &val);
    int changeValue(int ind, int val);
    void output();
    void clean();
};

#endif
