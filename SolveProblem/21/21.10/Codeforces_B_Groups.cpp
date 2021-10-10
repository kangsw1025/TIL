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
 
int n;
vector<int> vec[6];
 
bool solve(int l, int r) {
	set<int> a, b;
 
	for (int i = 0; i < vec[l].size(); i++) {
		a.insert(vec[l][i]);
	}
 
	for (int i = 0; i < vec[r].size(); i++) {
		int num = vec[r][i];
 
		if (a.find(num) != a.end()) {
			if (a.size() > n / 2) {
				a.erase(num);
				b.insert(num);
			}
		}
		else b.insert(num);
	}
 
	if (a.size() + b.size() == n && a.size() == b.size()) return true;
	return false;
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
 
 
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
 
		for (int i = 1; i <= 5; i++) vec[i].clear();
 
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= 5; j++) {
				int val;
				cin >> val;
				if (val == 1) vec[j].push_back(i);
			}
 
		if (n % 2) {
			cout << "NO\n";
			continue;
		}
 
		vector<pair<int, int>> day;
 
		for (int i = 1; i <= 5; i++)
			if (vec[i].size() >= n / 2) day.push_back({ vec[i].size(), i });
 
		sort(day.begin(), day.end());
		
		if (day.size() <= 1) {
			cout << "NO\n";
			continue;
		}
 
		if (day[day.size() - 1].first == n) {
			cout << "YES\n";
			continue;
		}
 
		bool can = false;
		for (int i = 0; i < day.size(); i++) {
			if (can) break;
			for (int j = i + 1; j < day.size(); j++) {
				if (solve(day[i].second, day[j].second)) {
					cout << "YES\n";
					can = true;
					break;
				}
			}
		}
 
		if (!can) cout << "NO\n";
	}
 
	return 0;
}