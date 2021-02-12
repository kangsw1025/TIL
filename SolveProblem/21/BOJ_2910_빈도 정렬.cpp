#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

map<int, int> info;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
	if (p1.second > p2.second) return true;
	else if (p1.second == p2.second) return info[p1.first] < info[p2.first];
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, c, num, idx = 1;;
	map<int, int> mp;
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (mp.find(num) == mp.end()) {
			mp[num] = 1;
			info[num] = idx++;
		}
		else mp[num]++;
	}
	vector<pair<int, int>> vec(mp.begin(), mp.end());
	sort(vec.begin(), vec.end(), cmp);
	for (auto itr : vec)
		for (int i = 0; i < itr.second; i++) cout << itr.first << ' ';
	return 0;
}
