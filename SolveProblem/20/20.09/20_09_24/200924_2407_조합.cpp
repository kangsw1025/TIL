#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int n, m;
string cache[101][101];

string st_add(string f, string s) {
	long long sum = 0;
	string rst;

	while (!f.empty() || !s.empty() || sum) {
		if (!f.empty()) {
			sum += f.back() - '0';
			f.pop_back();
		}
		if (!s.empty()) {
			sum += s.back() - '0';
			s.pop_back();
		}
		rst.push_back((sum % 10) + '0');
		sum /= 10;
	}
	reverse(rst.begin(), rst.end());
	return rst;
}

string solve(int n, int r) {
	if (n == r || r == 0) return "1";

	string& rst = cache[n][r];
	if (rst != "") return rst;
	rst = st_add(solve(n - 1, r - 1), solve(n - 1, r));
	return rst;
}

int main() {
	cin >> n >> m;
	cout << solve(n, m);
	return 0;
}