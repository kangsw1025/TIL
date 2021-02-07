#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n,m;
	string word;
	queue<int> que;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> word;
		if (word == "push") {
			cin >> m;
			que.push(m);
		}
		else if (word == "pop") {
			if (que.empty()) cout << "-1\n";
			else {
				cout << que.front() << "\n";
				que.pop();
			}
		}
		else if (word == "size") cout << que.size() << "\n";
		else if (word == "empty") cout << que.empty() << "\n";
		else if (word == "front") {
			if (que.empty()) cout << "-1\n";
			else cout << que.front()<<"\n";
		}
		else if (word == "back") {
			if (que.empty()) cout << "-1\n";
			else cout << que.back()<<"\n";
		}
	}
	return 0;
}