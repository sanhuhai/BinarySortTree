#include <iostream>
#include <queue>
#include <stack>
using namespace std;

typedef struct Node {
	char data;
	struct Node* leftchild, * rightchild;
}TNode ,*TLNode;

class Tree
{
public:
	Tree();
	~Tree();
	void createBinaryTree(TLNode& T);
	TLNode searchNode(TLNode &T , char data);
	void addNewNode(TLNode& T, char data);
	void preorderTraversal(TLNode& T);
	void inorderTraversal(TLNode& T);
	void postorderTraversal(TLNode& T);
	void levelTraversal(TLNode T);
	void nonRecuision(TLNode T);
	bool flag;
	TLNode root;
};

Tree::Tree()
{
	root = NULL;
	flag = false;
}

Tree::~Tree()
{
}

void Tree::createBinaryTree(TLNode& T) {
	char data;
	cin >> data;
	if (data == '#') {
		T = NULL;
	}
	else {
		T->data = data;
		T->leftchild = new Node;
		T->rightchild = new Node;
		createBinaryTree(T->leftchild);
		createBinaryTree(T->rightchild);
	}
}

void Tree::addNewNode(TLNode& T, char data) {
	if (!T) {
		T = new TNode;
		T->leftchild = NULL;
		T->rightchild = NULL;
		T->data = data;
		root = T;
		return;
	}
	if (T->data > data) {
		T->leftchild = new TNode;
		T->leftchild->data = data;
		T->leftchild->leftchild = NULL;
		T->leftchild->rightchild = NULL;
	}
	else {
		T->rightchild = new TNode;
		T->rightchild->data = data;
		T->rightchild->leftchild = NULL;
		T->rightchild->rightchild = NULL;
	}
}

TLNode Tree::searchNode(TLNode& T, char data) {
	if (T->data == data)return T;
	if (T->leftchild == NULL && T->data > data)return T;
	if (T->rightchild == NULL && T->data < data) return T;
	if (T->data < data && T->rightchild)return searchNode(T->rightchild, data);
	if (T->data > data && T->leftchild)return searchNode(T->leftchild, data);

}

void Tree::preorderTraversal(TLNode& T) {
	if (T) {
		cout << T->data << " ";
		preorderTraversal(T->leftchild);
		preorderTraversal(T->rightchild);
	}
}

void Tree::inorderTraversal(TLNode& T) {
	if (T) {
		inorderTraversal(T->leftchild);
		cout << T->data << " ";
		inorderTraversal(T->rightchild);
	}
}

void Tree::postorderTraversal(TLNode& T) {
	if (T) {
		postorderTraversal(T->leftchild);
		postorderTraversal(T->rightchild);
		cout << T->data << " ";
	}
}

void Tree::levelTraversal(TLNode T) {
	queue<TLNode> QT;
	QT.push(T);
	while (!QT.empty() && T) {
		cout << T->data << " ";
		if (T->leftchild) QT.push(T->leftchild);
		if (T->rightchild)QT.push(T->rightchild);
		QT.pop();
		if (!QT.empty()) T = QT.front();
	}
	putchar(10);
}

void Tree::nonRecuision(TLNode T) {
	stack <TLNode> S;
	while (!S.empty() || T) {
		while (T) {
			cout << T->data << " ";
			S.push(T);
			T = T->leftchild;
		}
		if (!S.empty()) {
			T = S.top();
			S.pop();
			T = T->rightchild;
		}

	}
}

int main() {
	Tree T;
	char data;
	while (cin >> data && data != '#') {
		if (!T.flag) {
			T.addNewNode(T.root,data);
			T.flag = true;
			cout << data << "根节点插入成功" << endl;
			continue;
		}
		TLNode temp = T.searchNode(T.root, data);
		if (temp->data == data) {
			cout << data <<"该数据已存在，插入失败" << endl;
			continue;
		}
		else {
			T.addNewNode(temp, data);
			cout << data << "该数据插入成功" << endl;
		}

		//T.inorderTraversal(T.root);
		//putchar(10);
	}
	T.inorderTraversal(T.root);
}