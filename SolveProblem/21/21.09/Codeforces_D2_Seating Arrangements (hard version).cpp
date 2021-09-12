#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
#include<cmath>
#include<set>
#include<string>
#include<cstring>
using namespace std;
 
map<int, int> place;
int arr[90001];
 
set<int> st;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
 
	int T;
	cin >> T;
	while (T--) {
		int n, m, ans = 0;
 
		cin >> n >> m;
 
		vector<int> vec, seat[301];
 
		for (int i = 0; i < n*m; i++) {
			cin>>arr[i];
			st.insert(arr[i]);
			vec.push_back(arr[i]);
		}
		sort(vec.begin(), vec.end());
 
		for (auto itr = st.begin(); itr != st.end(); itr++) {
			auto idx_itr = lower_bound(vec.begin(), vec.end(), *itr);
			int idx = idx_itr - vec.begin();
			place[*itr] = idx;
		}
 
		for (int i = 0; i < n * m; i++) {
			int idx = place[arr[i]]++;
 
			int mod = idx / m;
 
			auto itr = lower_bound(seat[mod].begin(), seat[mod].end(), arr[i]);
			if (itr == seat[mod].end()) {
				ans += seat[mod].size();
				seat[mod].push_back(arr[i]);
			}
			else {
				int index = itr - seat[mod].begin();
				seat[mod].insert(itr, arr[i]);
				ans += index;
			}
		}
 
		cout << ans << "\n";
	}
	return 0;
}