#include<iostream>
#include<queue>
#include<string>
using namespace std;

string a, b;

int solve() {
	queue<string> q;
	q.push(b);

	while (!q.empty()) {
		string n = q.front();
		q.pop();
		
		if (n == a) return 1;
		if (n.length() < a.length()) return 0;

		if (n[n.length() - 1] == 'A') {
			string nw = "";
			for (int i = 0; i < n.length() - 1; i++) nw += n[i];
			q.push(nw);
		}
		else if (n[n.length() - 1] == 'B') {
			string nw = "";
			for (int i = n.length() - 2; i >= 0; i--) nw += n[i];
			q.push(nw);
		}
	}

	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> b;
	cout<<solve();
	return 0;
}