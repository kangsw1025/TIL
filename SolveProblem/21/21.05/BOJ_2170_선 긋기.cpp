#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	vector<pair<int, int>> vec;

	int T;
	cin >> T;
	while (T--) {
		int a, b;
		cin >> a >> b;
		vec.push_back({ a,b });
	}
	sort(vec.begin(), vec.end());
 
	int start, end, ans = 0;
	for (int i = 0; i < vec.size(); i++) {
		if (i == 0) {
			start = vec[i].first;
			end = vec[i].second;
		}
		else {
			if (vec[i].first > end) {
				ans += end - start;
				start = vec[i].first;
				end = vec[i].second;
			}
			else end = max(end,vec[i].second);
		}
	}
	ans += end - start;
	cout << ans;
	return 0;
}