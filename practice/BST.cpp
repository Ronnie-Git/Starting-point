#include <iostream>
using namespace std;

class Node {
public:
	Node();	
	int iKey;
	Node *pLChild;
	Node *pRChild;
};

class BTree {
public:
	BTree();
	~BTree();
	Node *InsertTree(int iKey);
	Node * SearchTree(int iKey);
	Node * DeleteTree(int iKey);
	void DestroyTree();
	void ShowTree();
private:
	Node *Search(Node *pNode, int iKey);
	Node *Insert(Node* pHead,  int iKey);
	Node * Delete(Node *pHead, int iKey);
	void Destroy(Node *pHead);
	void Show(Node *pHead);
public:
	Node *m_pRoot;
};


Node::Node() {
	iKey =0;
	pLChild = NULL;
	pRChild = NULL;
}

BTree::BTree() {
	m_pRoot = NULL;
}

BTree::~BTree() {
	DestroyTree();
}


Node *BTree::Insert(Node* pHead,  int iKey) {
	if (pHead == NULL) {
		Node *pNow = new Node();
		pNow->iKey = iKey;
		pNow->pLChild = pNow->pRChild = NULL;
		return pNow;
	}
	if (iKey < pHead->iKey) {
		pHead->pLChild = Insert(pHead->pLChild, iKey);
	} else {
		pHead->pRChild = Insert(pHead->pRChild,iKey);
	}

	return pHead;
}

Node *BTree::Search(Node *pNode, int iKey) {
	if (pNode == NULL) return NULL;
	if (iKey == pNode->iKey) {
		return pNode;
	} else if (iKey < pNode->iKey) {
		return Search(pNode->pLChild, iKey);
	} else  {
		return Search(pNode->pRChild, iKey);
	}
}

void BTree::Show(Node *pHead) {
//cout << "debug ............begin show pHead=" << pHead << endl;
	if (pHead != NULL) {
		Show(pHead->pLChild);
		cout << pHead->iKey << " ";
		Show(pHead->pRChild);
	}	
}

Node * BTree::Delete(Node *pHead, int iKey) {
	Node *p, *q;
	if (pHead->iKey == iKey) {
		if (pHead->pLChild == NULL && pHead->pRChild == NULL) {
			delete pHead;
			return NULL;
		} else if (pHead->pLChild == NULL) {
			p = pHead->pRChild;
			delete pHead;
			return p; 
		} else if (pHead->pRChild == NULL) {
			p = pHead->pLChild;
			delete pHead;
			return p;
		} else {
			p = q = pHead->pRChild;
			while (p->pLChild != NULL) {
				//找到左子树最左孩子结点
				p = p->pLChild;
			}
			//原左子树作为左孩子
			p->pLChild = pHead->pLChild;
			delete pHead;
			return q;
		}
	}

	if(pHead->iKey > iKey && pHead->pLChild != NULL) {
		pHead->pLChild = Delete(pHead->pLChild, iKey);
	}
	if(pHead->iKey < iKey && pHead->pRChild != NULL) {
		pHead->pRChild = Delete(pHead->pRChild, iKey);
	}
	return pHead;
}

void BTree::Destroy(Node * pHead) {
	if (pHead != NULL) {
		Destroy(pHead->pLChild);
		Destroy(pHead->pRChild);
		delete pHead;
	}
}

Node * BTree::SearchTree(int iKey) {
	return Search(m_pRoot, iKey);
}


Node *BTree::InsertTree(int iKey) {
	m_pRoot = Insert(m_pRoot, iKey);
}


Node * BTree::DeleteTree(int iKey) {
	return Delete(m_pRoot,iKey);
}

void BTree::DestroyTree() {
	Destroy(m_pRoot);
}

void BTree::ShowTree() {
	Show(m_pRoot);
}

int main() {
	BTree *pBTree = new BTree();

	pBTree->InsertTree(6);
	pBTree->InsertTree(4);
	pBTree->InsertTree(9);
	pBTree->InsertTree(8);
	pBTree->InsertTree(7);
	pBTree->InsertTree(3);
	pBTree->InsertTree(5);
	pBTree->InsertTree(10);

	cout << "root:" << pBTree->m_pRoot << endl;
	pBTree->ShowTree();
	cout << endl;
	Node *pNode = pBTree->SearchTree(3);
	if (pNode != NULL) {
		cout << "search key = " << pNode->iKey << "ok" << endl;
	}

	pBTree->DeleteTree(4);
	cout << "after delete 4 "<< endl;
	pBTree->ShowTree();
	pBTree->DeleteTree(7);
	cout << "after delete 7 "<< endl;
	pBTree->ShowTree();

	delete pBTree;
	return 0;
}

