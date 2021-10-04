#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<map>
#include<cmath>
#include<deque>
#include<set>
using namespace std;

const int MAX = 1e5 + 1;
int A[MAX], B[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int n, x;
		vector<pair<int, int>> v;
		cin >> n >> x;
		for (int i = 1; i <= n; i++) {
			cin >> A[i];
			B[i] = A[i];
		}
		sort(B+1, B+n+1);

		bool can = true;

		for (int i = n-x+1; i <= x; i++) {
			if (A[i] != B[i]) can = false;
		}

		if (can) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}