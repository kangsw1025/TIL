#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

#define INF 987654321

int n, ans = INF;
string w, word, ch;

void push(int idx) {
	if (idx > 0)
		ch[idx - 1] = (ch[idx - 1] == '0') ? '1' : '0';
	ch[idx] = (ch[idx] == '0') ? '1' : '0';
	if(idx<n-1)
		ch[idx + 1] = (ch[idx + 1] == '0') ? '1' : '0';
}

void solve(int idx, int cnt) {
	if (idx == n - 1) {
		if (ch == word)
			ans = min(ans, cnt);

		push(idx);
		if (ch == word)
			ans = min(ans, cnt + 1);
		return;
	}

	if (ch[idx - 1] == word[idx - 1])
		solve(idx + 1, cnt);
	push(idx);
	if (ch[idx - 1] == word[idx - 1])
		solve(idx + 1, cnt + 1);
	push(idx);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	cin >> w >> word;
	
	ch = w;
	solve(1, 0);

	ch = w;
	push(0);
	solve(1, 1);
	if (ans == INF) cout << -1;
	else cout << ans;
	
	return 0;
}