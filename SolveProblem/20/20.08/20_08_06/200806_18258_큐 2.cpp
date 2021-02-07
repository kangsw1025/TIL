#include<iostream>
#include<deque>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	deque<int> q;

	int n;
	string w;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> w;
		if (w == "push") {
			int num;
			cin >> num;
			q.push_back(num);
		}
		else if (w == "front") {
			if (q.empty()) cout << "-1\n";
			else cout << q.front() << "\n";
		}
		else if (w == "pop") {
			if (q.empty()) cout << "-1\n";
			else {
				cout << q.front() << "\n";
				q.pop_front();
			}
		}
		else if (w == "size") cout << q.size() << "\n";
		else if (w == "back") {
			if (q.empty()) cout << "-1\n";
			else cout << q.back() << "\n";
		}
		else if (w == "empty") {
			if (q.empty()) cout << "1\n";
			else cout << "0\n";
		}
	}
	return 0;
}