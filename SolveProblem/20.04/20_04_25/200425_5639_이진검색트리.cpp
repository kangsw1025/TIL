#include<iostream>
using namespace std;

class Node
{
private:
	int num;
	Node* r;
	Node* l;
public:
	Node(int n = 0) {
		num = n;
		r = NULL;
		l = NULL;
	}
	int getnum() {
		return num;
	}
	Node* getleft() {
		return l;
	}
	Node* getright() {
		return r;
	}
	void setnum(int n) {
		num = n;
	}
	void setleft(Node* n)
	{
		l = n;
	}
	void setright(Node* n)
	{
		r = n;
	}
};

class BST
{
private:
	Node* root;
public:
	BST() {
		root = NULL;
	}
	void insert(Node* n, Node* nod)
	{
		if (nod == NULL) {
			nod = n;
		}
		else {
			if (n->getnum() < nod->getnum()) {
				if (nod->getleft() == NULL)  nod->setleft(n);
				else insert(n, nod->getleft());
			}
			else {
				if (nod->getright() == NULL) nod->setright(n);
				else insert(n, nod->getright());
			}
		}
	}
	Node* getroot() {
		return root;
	}
	void print(Node* n)
	{
		if (n->getleft() != NULL) print(n->getleft());
		if (n->getright() != NULL) print(n->getright());
		cout << n->getnum() << "\n";
	}
	void setroot(Node* n)
	{
		root = n;
	}
};

int main()
{
	int n;
	BST *Tree = new BST();
	while (cin >> n) {
		if (Tree->getroot() == NULL) Tree->setroot(new Node(n));
		else Tree->insert(new Node(n), Tree->getroot());
	}
	Tree->print(Tree->getroot());
	return 0;
}