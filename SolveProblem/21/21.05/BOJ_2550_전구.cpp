#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

const int Max = 1e5 + 1;
int n;
int arr[Max];
int first[Max];
int cache[Max];
vector<pair<int, int>> vec;
pair<int, int> ans[Max];
vector<int> an;

int solve() {
	int idx = 0;
	cache[0] = vec[0].second;
	ans[0] = { 0,vec[0].first };

	for (int i = 1; i < n; i++) {
		if (vec[i].second > cache[idx]) {
			cache[++idx] = vec[i].second;
			ans[i] = { idx,vec[i].first };
		}
		else {
			int idx2 = lower_bound(cache, cache + idx, vec[i].second) - cache;
			cache[idx2] = vec[i].second;
			ans[i] = { idx2,vec[i].first };
		}
	}
	return idx + 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int num;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		first[arr[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		cin >> num;
		vec.push_back({ first[num],i});
	}
	sort(vec.begin(), vec.end());
	int rst = solve();
	cout << rst-- << "\n";
	for (int i = n - 1; i >= 0; i--) 
		if (ans[i].first == rst) {
			an.push_back(arr[ans[i].second]);
			rst--;
		}
	sort(an.begin(), an.end());
	for (int i = 0; i < an.size(); i++) cout << an[i] << ' ';

	return 0;
}