/*************************************************************************
	> File Name: 11.二进制中1的个数.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年03月26日 星期二 20时45分00秒
 ************************************************************************/

class Solution {
public:
     int  NumberOf1(int n) {
         unsigned int x = n;
         x = ((x & 0xAAAAAAAA) >> 1) + (x & 0x55555555);
         x = ((x & 0xCCCCCCCC) >> 2) + (x & 0x33333333);
         x = ((x & 0xF0F0F0F0) >> 4) + (x & 0x0F0F0F0F);
         x = ((x & 0xFF00FF00) >> 8) + (x & 0x00FF00FF);
         x = ((x & 0xFFFF0000) >> 16) + (x & 0x0000FFFF);
         return x;
     }
};
