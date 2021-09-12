#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;
 
int arr[301];
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
 
	int T;
	cin >> T;
	while (T--) {
		int n, m, ans = 0;
		cin >> n >> m;
		vector<int> vec;
		for (int i = 0; i < m; i++) {
			int sight;
			cin >> sight;
 
			auto itr = lower_bound(vec.begin(), vec.end(), sight);
			if (itr == vec.end()) {
				ans += vec.size();
				vec.push_back(sight);
			}
			else {
				int idx = itr - vec.begin();
				vec.insert(itr, sight);
				ans += idx;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}