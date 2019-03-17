/*************************************************************************
	> File Name: HR_jsk.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2019年01月09日 星期三 16时33分51秒
 ************************************************************************/

#include <iostream>
#include <string>

using namespace std;

class People {
public :
    People(int new_Num, string new_N, string new_G, string new_ID, double new_S) : number(new_Num), name(new_N), gender(new_G), ID(new_ID), salary(new_S) {
        cout << "calling the constructor" << endl;
    } 
    People(People &p) : name(p.name), gender(p.gender), ID(p.ID), salary(p.salary) {
        number = p.number + 1;
        cout << "calling the copy constructor" << endl;
    }
    void set_name(string new_name) {
        name = new_name;
    }
    void set_salary(double new_S) {
        salary = new_S;
    }
    void show() {
        cout << number << " " << name << " " << gender << " " << ID << " " << salary << endl;
    }
    ~People() {
        cout << "calling the destructor" << endl;
    } 
private :
    int number;
    string name;
    string gender;
    string ID;
    double salary;
};

int main() {
    People p1(01, "qratosone", "Male", "2010201326", 4800.0);
    People p2(p1);
    p2.set_name("He");
    p2.set_salary(301.301);
    p1.show();
    p2.show();
    string new_name;
    cin>>new_name;
    People p3(p2);
    p3.set_name(new_name);
    p3.show();
    return 0;
}
