#include<iostream>
#include<vector>
#include<bitset>
using namespace std;

const int mx = 3e6;

vector<int> fib = { 1,1 };
int gn[mx+1];
bitset<31> mex;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (fib.back() <= mx) {
		fib.push_back(fib[fib.size() - 2] + fib[fib.size() - 1]);
	}

	for (int i = 1; i <= mx; i++) {
		for (int f : fib) {
			int state = i - f;
			if (state < 0) break;
			mex[gn[state]] = 1;
		}

		while (mex[gn[i]]) gn[i]++;
		mex.reset();
	}

	int T, rst = 0;
	cin >> T;
	while (T--) {
		int p; cin >> p;
		rst ^= gn[p];
	}

	if (rst == 0) cout << "cubelover";
	else cout << "koosaga";
	return 0;
}