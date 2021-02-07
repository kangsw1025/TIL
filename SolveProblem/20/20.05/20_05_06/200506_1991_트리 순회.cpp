#include<iostream>
using namespace std;

class Node
{
private:
	char word;
	Node* left;
	Node* right;
public:
	Node(char wo) {
		word = wo;
		left = NULL;
		right = NULL;
	}
	char getword() {
		return word;
	}
	Node* getleft() {
		return left;
	}
	Node* getright() {
		return right;
	}
	void setleft(Node* n) {
		left = n;
	}
	void setright(Node* n) {
		right = n;
	}
	void be() {
		cout << word;
		if(getleft()!=NULL) left->be();
		if (getright() != NULL) right->be();
	}
	void mid() {
		if (getleft() != NULL) left->mid();
		cout << word;
		if (getright() != NULL) right->mid();
	}
	void af() {
		if (getleft() != NULL) left->af();
		if (getright() != NULL) right->af();
		cout << word;
	}

};

class NodeTree
{
private:
	Node* root;
public:
	NodeTree() {
		root = new Node('A');
	}
	Node* getroot() {
		return root;
	}
	void find(Node* n, char word, char l, char r) {
		if (n->getword() == word) {
			if (l != '.') n->setleft(new Node(l));
			if (r != '.') n->setright(new Node(r));
		}
		else {
			if (n->getleft() != NULL) find(n->getleft(), word, l, r);
			if (n->getright() != NULL) find(n->getright(), word, l, r);
		}
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	char a, b, c;
	cin >> n;
	NodeTree *nt = new NodeTree();
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		nt->find(nt->getroot(),a,b,c);
	}
	nt->getroot()->be();
	cout << "\n";
	nt->getroot()->mid();
	cout << "\n";
	nt->getroot()->af();
	return 0;
}