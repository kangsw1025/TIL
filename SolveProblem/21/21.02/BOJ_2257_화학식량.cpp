#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string word;
	stack<char> st;
	stack<int> num;

	cin >> word;
	for (int i = 0; i < word.length(); i++) st.push(word[i]);

	int ans = 0, value = 1;
	while (!st.empty()) {
		if (st.top() >= '2' && st.top() <= '9') {
			int cal = st.top() - '0';
			st.pop();
			if (st.top() == ')') {
				value *= cal;
				num.push(cal);
			}
			else if (st.top() == 'H') ans += value * cal;
			else if (st.top() == 'C') ans += 12 * value * cal;
			else if (st.top() == 'O') ans += 16 * value * cal;
		}
		else if (st.top() == ')') num.push(1);
		else if (st.top() == '(') {
			if (value != 1) {
				value /= num.top();
				num.pop();
			}
		}
		else {
			if (st.top() == 'H') ans += value;
			else if (st.top() == 'C') ans += 12 * value;
			else if (st.top() == 'O') ans += 16 * value;
		}
		st.pop();
	}
	cout << ans;
	return 0;
}