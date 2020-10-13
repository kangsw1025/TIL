#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main() {
	int T, ans = 0;
	cin >> T;
	while (T--) {
		string word;
		cin >> word;

		stack<char> st;

		for (int i = 0; i < word.length(); i++) {
			if (!st.empty() && st.top() == word[i]) st.pop();
			else st.push(word[i]);
		}

		if (st.empty()) ans++;
	}
	cout << ans;
	return 0;
}