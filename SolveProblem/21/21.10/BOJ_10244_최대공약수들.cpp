#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

map<int, bool> dp[100001];
int arr[100001];
bool sosu[101];
map<set<int>, int> mp;

int gcd(int a, int b) {
	if (a < b) swap(a, b);
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	while (1) {
		cin >> n;
		for (int i = 0; i < n; i++) dp[i].clear();
		if (n == 0) break;
		set<int> s;
		vector<int> v;
		for (int i = 0; i < n; i++) {
			int val;
			cin >> val;
			v.push_back(val);
		}
		for (int i = 0; i < v.size(); i++) {
			int cd = v[i];
			for (int j = i; j < v.size(); j++) {
				cd = gcd(cd, v[j]);
				s.insert(cd);
				if (cd == 1 || dp[j][cd]) break;
				dp[j][cd] = true;
			}
		}

		cout << s.size() << "\n";
	}
	return 0;
}