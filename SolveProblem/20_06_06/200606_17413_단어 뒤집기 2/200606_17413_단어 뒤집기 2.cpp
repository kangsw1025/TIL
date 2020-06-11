#include<iostream>
#include<string>
#include<queue>
#include<stack>
using namespace std;

int main()
{
	queue<char> q;
	stack<char> st;
	string word;
	bool check = false;
	getline(cin, word);
	for (int i = 0; i < word.length(); i++) {
		if (check == true) {
			if (word[i] == '>') {
				while (!q.empty()) {
					cout << q.front();
					q.pop();
				}
				cout << '>';
				check = false;
			}
			else q.push(word[i]);
		}
		else if (check == false) {
			if (word[i] == '<') {
				while (!st.empty()) {
					cout << st.top();
					st.pop();
				}
				cout << '<';
				check = true;
			}
			else if (word[i] == ' ') {
				while (!st.empty()) {
					cout << st.top();
					st.pop();
				}
				cout << ' ';
			}
			else st.push(word[i]);
		}
	}
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
	return 0;
}