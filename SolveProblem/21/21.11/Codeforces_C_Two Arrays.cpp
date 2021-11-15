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
 
bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) return a.second > b.second;
	return a.first < b.first;
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
 
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
 
		vector<pair<int, int>> a;
		vector<int> b;
 
		for (int i = 0; i < n; i++) {
			int val;
			cin >> val;
			a.push_back({ val,i });
		}
 
		for (int i = 0; i < n; i++) {
			int val;
			cin >> val;
			b.push_back(val);
		}
		
		sort(a.begin(), a.end(),cmp);
		sort(b.begin(), b.end());
 
		bool isStop = false;
		for (int i = 0; i < n; i++) {
			if (a[i].first == b[i] || a[i].first + 1 == b[i]) continue;
			else {
				isStop = true;
				break;
			}
		}
 
		if (isStop) cout << "NO\n";
		else cout << "YES\n";
	}
 
	return 0;
}