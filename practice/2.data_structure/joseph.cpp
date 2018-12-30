#include<iostream>
using namespace std;

struct Node {
    int data;
	int num;
    Node *next;
};
 
class Joseph {
public:
    Joseph();//���캯��,����������
    Node *GetNode(int data, int num);
    void Create(int);//��������n��Ԫ�صĵ�ѭ������
    void Deal(int m);//����Լɪ�� 
private:
    Node *tail;
	int len;
};
  
Joseph::Joseph() {
    tail = new Node;//����һ���µ�Ԫ��tailָ���µ�Ԫ 
    tail->next = NULL;
	len = 0;
}

Node *Joseph::GetNode(int data, int num) {
    Node *p = new Node;//����һ���µ�Ԫ��tailָ���µ�Ԫ 
    p->data = data;
    p->num = num;
    p->next = NULL;
	return p;
}

void Joseph::Create(int n) {//����n��Ԫ�ص����� 
	int m;
	Node *p, *q;
	
	cout << "������" << n << "���˸��Ե�����:  " << endl;
	len = n;
	cin >> m;//��һ�Σ���βָ�����ڵ�Ԫ����ֵ 
	
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
 
void Joseph::Deal(int m) {//����Լɪ�� 
    Node *q, *p = tail;//pָ������ĵ�һ��Ԫ�� 

    while(len--) {
        while (--m) p = p->next;//pָ��Ҫɾ����ǰһ��Ԫ�� 
    	
		q = p->next;//qָ��Ҫɾ����Ԫ�� 
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
    cout << "������m�ĳ�ֵ�� " << endl;
    cin >> m;
    cout << "������n��ֵ�� " << endl;
    cin >> n; 
    
    joseph.Create(n);//����Լɪ�� 
    joseph.Deal(m);//����Լɪ�� 
    
	return 0; 
}
