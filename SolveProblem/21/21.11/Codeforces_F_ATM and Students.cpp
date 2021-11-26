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
 
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
 
	int T;
	cin >> T;
	while (T--) {
		vector<pair<long long, pair<int, int>>> v;
		int n, money;
 
		cin >> n >> money;
 
		for (int i = 1; i <= n; i++) {
			int val;
			cin >> val;
			if (v.empty()) {
				v.push_back({ val,{1,1} });
			}
			else {
				if (v.back().first >= 0 && val >= 0) {
					v.back().first += val;
					v.back().second.second++;
				}
				else v.push_back({ val,{i,1} });
			}
		}
 
		int l, r, mx = 0;
		for (int i = 0; i < v.size(); i++) {
			if (v[i].first < 0 && money + v[i].first < 0) continue;
 
			int start = v[i].second.first;
			int date = v[i].second.second;
			long long state = money + v[i].first;
 
			if (date > mx) {
				mx = date;
				l = start;
				r = start + date - 1;
			}
			for (int j = i + 1; j < v.size(); j++) {
				if (v[j].first < 0 && state + v[j].first < 0) break;
 
				state += v[j].first;
				date += v[j].second.second;
 
				if (date > mx) {
					mx = date;
					l = start;
					r = start + date - 1;
				}
			}
		}
		if (mx == 0) cout << "-1\n";
		else cout << l << ' ' << r << "\n";
	}
 
	return 0;
}
