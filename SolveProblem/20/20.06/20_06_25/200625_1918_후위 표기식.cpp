#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	stack<char> st;
	string w;

	cin >> w;
	for (int i = 0; i < w.length(); i++) {
		if (w[i] >= 'A' && w[i] <= 'Z') cout << w[i];
		else {
			if (w[i] == '(') st.push(w[i]);
			else if (w[i] == ')') {
				while (!st.empty() && st.top() != '(') {
					cout << st.top();
					st.pop();
				}
				st.pop();
			}
			else if (w[i] == '*' || w[i] == '/') {
				while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
					cout << st.top();
					st.pop();
				}
				st.push(w[i]);
			}
			else if (w[i] == '+' || w[i] == '-') {
				while (!st.empty() && st.top()!='(') {
					cout << st.top();
					st.pop();
				}
				st.push(w[i]);
			}
		}
	}
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
	return 0;
}