#include<iostream>
using namespace std;

struct Node {
    int data;
	int num;
    Node *next;
};
 
class Joseph {
public:
    Joseph();//构造函数,创建空链表
    Node *GetNode(int data, int num);
    void Create(int);//创建具有n个元素的单循环链表
    void Deal(int m);//处理约瑟夫环 
private:
    Node *tail;
	int len;
};
  
Joseph::Joseph() {
    tail = new Node;//分配一个新单元，tail指向新单元 
    tail->next = NULL;
	len = 0;
}

Node *Joseph::GetNode(int data, int num) {
    Node *p = new Node;//分配一个新单元，tail指向新单元 
    p->data = data;
    p->num = num;
    p->next = NULL;
	return p;
}

void Joseph::Create(int n) {//创建n个元素的链表 
	int m;
	Node *p, *q;
	
	cout << "请输入" << n << "个人各自的密码:  " << endl;
	len = n;
	cin >> m;//第一次，在尾指针所在单元输入值 
	
	tail->data = m;
	tail->num = 1;
	tail->next = tail;
	
	for (int i = 2; i <= n; i++) {
    	cin >> m;
    	p = GetNode(m, i);
    	p->next = tail->next;
		tail->next = p;
		tail = p;
    }
    
	return ;
}
 
void Joseph::Deal(int m) {//处理约瑟夫环 
    Node *q, *p = tail;//p指向链表的第一个元素 

    while(len--) {
        while (--m) p = p->next;//p指向要删除的前一个元素 
    	
		q = p->next;//q指向要删除的元素 
    	m = q->data;
    	cout << q->num <<" ";

		p->next = q->next;
	    delete q;				
	}
	cout << endl;
	
    return ;
}
 
 
int main() {
	int m, n;
    Joseph joseph;
    cout << "请输入m的初值： " << endl;
    cin >> m;
    cout << "请输入n的值： " << endl;
    cin >> n; 
    
    joseph.Create(n);//创建约瑟夫环 
    joseph.Deal(m);//处理约瑟夫环 
    
	return 0; 
}
