#include<iostream>
using namespace std;

const int MAX = 1e5 + 1;

int inOrder[MAX], postOrder[MAX], idx[MAX];

void preOrder(int ins, int ine, int pos, int poe) {
	if (ins > ine || pos > poe) return;

	int root = postOrder[poe];
	cout << root << ' ';
	preOrder(ins, idx[root] - 1, pos, pos + (idx[root] - ins) - 1);
	preOrder(idx[root] + 1, ine, pos + (idx[root] - ins), poe - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) cin >> inOrder[i];
	for (int i = 0; i < n; i++) cin >> postOrder[i];
	for (int i = 0; i < n; i++) idx[inOrder[i]] = i;

	preOrder(0, n - 1, 0, n - 1);
	return 0;
}