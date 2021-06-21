#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int n, ans = -2e9;
string word;

int cal(int a, int b, char op) {
	if (op == '+') return a + b;
	if (op == '-') return a - b;
	if (op == '*') return a * b;
}

void solve(int idx, int sum) {
	if (idx >= n) {
		ans = max(ans, sum);
		return;
	}

	if (idx == 0) solve(idx + 2, cal(sum, word[idx] - '0', '+'));
	else solve(idx + 2, cal(sum, word[idx] - '0', word[idx - 1]));
	if (idx + 2 < n) {
		if (idx) solve(idx + 4, cal(sum, cal(word[idx] - '0', word[idx + 2] - '0', word[idx + 1]), word[idx - 1]));
		else solve(idx + 4, cal(sum, cal(word[idx] - '0', word[idx + 2] - '0', word[idx + 1]), '+'));
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> word;
	solve(0, 0);
	cout << ans;
	return 0;
}