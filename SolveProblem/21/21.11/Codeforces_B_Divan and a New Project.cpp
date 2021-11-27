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
#include<cstdlib>
using namespace std;
 
long long arr[200002];
 
bool cmp(pair<int, int> p1, pair<int, int> p2) {
	return p1.first > p2.first;
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
 
	int T;
	cin >> T;
	while (T--) {
		int n;
		vector<pair<int, int>> v;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			int val;
			cin >> val;
			v.push_back({ val,i });
		}
 
		sort(v.begin(), v.end(), cmp);
 
		arr[0] = (n + 1) / 2;
		int before = arr[0];
 
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) {
				arr[v[i].second] = before + i + 1;
				before += i + 1;
			}
			else {
				arr[v[i].second] = before - i - 1;
				before -= i + 1;
			}
		}
		long long dst = 0;
		for (int i = 1; i <= n; i++) {
			dst += 2LL * (long long)(abs(arr[0] - arr[v[i - 1].second])) * (long long)(v[i - 1].first);
		}
		cout << dst << "\n";
		for (int i = 0; i <= n; i++) cout << arr[i] << ' ';
		cout << "\n";
	}
	return 0;
 
	return 0;
}