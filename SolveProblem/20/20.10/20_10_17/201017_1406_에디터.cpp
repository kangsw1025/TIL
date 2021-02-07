#include<iostream>
#include<string>
#include<stack>
using namespace std;

stack<char> head, tail;

int main() {
	int T;
	string word;
	cin >> word;
	for (int i = 0; i < word.length(); i++) head.push(word[i]);
	
	cin >> T;
	while (T--) {
		char op;
		cin >> op;
		if (op == 'L') {
			if (!head.empty()) {
				tail.push(head.top());
				head.pop();
			}
		}
		else if (op == 'D') {
			if (!tail.empty()) {
				head.push(tail.top());
				tail.pop();
			}
		}
		else if (op == 'B') {
			if (!head.empty()) head.pop();
		}
		else if (op == 'P') {
			char w;
			cin >> w;
			head.push(w);
		}
	}
	while (!head.empty()) {
		tail.push(head.top());
		head.pop();
	}
	while (!tail.empty()) {
		cout << tail.top();
		tail.pop();
	}
	return 0;
}