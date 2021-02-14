#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
	int ans = 0, stick = 0;
	string word;
	stack<char> st;
	cin >> word;
	for (int i = 0; i < word.length(); i++) st.push(word[i]);

	while (!st.empty()) {
		if (st.top() == ')') {
			st.pop();
			if (st.top() == '(') {
				ans += stick;
				st.pop();
			}
			else stick++;
		}
		else {
			ans ++;
			stick--;
			st.pop();
		}
	}
	cout << ans;
	return 0;
}