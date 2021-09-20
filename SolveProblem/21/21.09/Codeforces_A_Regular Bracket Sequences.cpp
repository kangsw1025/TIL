#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
#include<string>
#include<map>
#include<stack>
using namespace std;
 
const int INF = 2e9 + 1;
 
void show(int left, int right) {
	if (left == 0) return;
 
	for (int i = 0; i < left; i++) cout << '(';
	for (int i = 0; i < left; i++) cout << ')';
	for (int i = 0; i < right; i++) cout << "()";
	cout << "\n";
	show(left - 1, right + 1);
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
 
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		
		show(n, 0);
	}
 
 
 
	return 0;
}