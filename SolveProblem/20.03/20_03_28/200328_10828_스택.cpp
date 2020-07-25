#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	stack<int> st;
	int n, m;
	string word;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> word;
		if (word == "push") {
			cin >> m;
			st.push(m);
		}
		else if (word == "top") {
			if (st.size() == 0) cout << "-1\n";
			else cout << st.top()<<"\n";
		}
		else if (word == "size") cout << st.size() << "\n";
		else if (word == "empty") cout << st.empty() << "\n";
		else if (word == "pop") {
			if (st.empty()) cout << "-1\n";
			else {
				cout << st.top() << "\n";
				st.pop();
			}
		}
	}
	return 0;
}