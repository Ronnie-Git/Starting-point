/*************************************************************************
	> File Name: BST.cpp
	> Author: x
	> Mail: x.com
	> Created Time: 2018年12月19日 星期三 17时49分46秒
 ************************************************************************/

#include <iostream>

using namespace std;

class btree {
public:
	btree *left;
	btree *right;
	int data;
    btree(int i):left(NULL),right(NULL),data(i){}
    ~btree();
 
	void insert(int a);
	static void inorder(const btree*);//中序遍历
	static void rinorder(const btree*);//中序遍历，先遍历右子树
};

void btree::insert(int a) {
	if (a < data && left)
		left->insert(a);
	else if (a < data && !left)
		left = new btree(a);
	else if (a > data && right)
		right->insert(a);
	else if (a > data && !right)
		right = new btree(a);
}
 
void btree::inorder(const btree* b)
{
   if (b != NULL)
   {
   	  inorder(b->left);
   	  cout<<b->data<<" ";
   	  inorder(b->right);
   }
}
 
void btree::rinorder(const btree* b)
{
   if (b != NULL)
   {
   	  rinorder(b->right);
   	  cout<<b->data<<" ";
   	  rinorder(b->left);
   }
}
btree::~btree()
{
	if (left)
		delete left;
	if (right)
		delete right;
}
 
void main()
{
   int zu[]={45,1,9,12,8,4821,4,5,1651,51};
   btree *root=new btree(zu[0]);
 
   for (int i = 1; i < 10; ++i)
   {
   	 root->insert(zu[i]);
   }
 
   btree::inorder(root);
   cout<<endl;
   btree::rinorder(root);
   cout<<endl;
   delete root;
}

