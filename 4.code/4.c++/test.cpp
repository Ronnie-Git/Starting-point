/*************************************************************************
	> File Name: test.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2018年12月25日 星期二 20时23分16秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
/*
using std::cin;
using std::cout;
using std::endl;
using std::string;
*/
using namespace std;
namespace my_lib {
    class People {
        private:
            int age;
            string name;
        public:
        People(string s) {
            cout << "People" << endl;
            name = s;
        }
        int getAge() {
            return age;
        }
        string getName() {
            return name;
        }
    };
}

using my_lib::People;

int main() {
    //my_lib::People p("wrf");
    //my_lib::People *p1 = new People("wrf");
    People p("wrf");
    People *p1 = new People("wrf1");
    cout << p.getName() << endl;
    cout << p1->getName() << endl;
    delete p1;
    return 0;
}
