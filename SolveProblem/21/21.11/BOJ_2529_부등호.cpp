#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int n;
char arr[10];
bool use[10];
vector<string> v;

void solve(int idx, string s) {
	if (idx == n) {
		v.push_back(s);
		return;
	}

	if (arr[idx] == '>') {
		int last = s[s.length() - 1] - '0';
		for (int i = 0; i < last; i++) {
			if (!use[i]) {
				char w = '0' + i;
				use[i] = true;
				solve(idx + 1, s + w);
				use[i] = false;
			}
		}
	}
	else {
		int last = s[s.length() - 1] - '0';
		for (int i = last+1; i <= 9; i++) {
			if (!use[i]) {
				char w = '0' + i;
				use[i] = true;
				solve(idx + 1, s + w);
				use[i] = false;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = 0; i <= 9; i++) {
		string s = "";
		char a = '0' + i;
		use[i] = true;
		solve(0, s+a);
		use[i] = false;
	}

	sort(v.begin(), v.end());
	cout << v[v.size() - 1] << "\n";
	cout << v[0];
	return 0;
}