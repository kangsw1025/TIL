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
#include<vector>
using namespace std;
 
const int mod = 1e9 + 7;
 
int power(int n, int k) {
	long long rst = 1;
	long long aa = n;
	while (k) {
		if (k % 2) rst = rst * aa % mod;
		k /= 2;
		aa = aa * aa % mod;
	}
	return rst;
}
 
int solve(int n, int k) {
	vector<int> v;
 
	while (k) {
		for (int i = 0;; i++) {
			int cnt = pow(2, i);
			if (k > cnt) {
				k -= cnt;
			}
			else {
				v.push_back(i);
				k--;
				break;
			}
		}
	}
 
	long long sum = 0;
 
	for (int i = 0; i < v.size(); i++)
		sum = (sum + power(n,v[i])) % mod;
 
	return sum;
}
 
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
 
	int T;
 
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
 
		cout << solve(n, k) << "\n";
	}
 
	return 0;
}