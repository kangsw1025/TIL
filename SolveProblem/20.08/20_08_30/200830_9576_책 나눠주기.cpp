#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

bool check[1001];

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (!(a.second == b.second)) return a.second < b.second;
	return a.first < b.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		memset(check, false, sizeof(check));

		int a, b;
		cin >> a >> b;
		vector<pair<int, int>> vec;
		for (int i = 0; i < b; i++) {
			int f, s;
			cin >> f >> s;
			vec.push_back(make_pair(f, s));
		}

		sort(vec.begin(), vec.end(), cmp);
		int ans = 0;
		for (int j = 0; j < b; j++) {
			for(int k=vec[j].first;k<=vec[j].second;k++)
				if (!check[k]) {
					check[k] = true;
					ans++;
					break;
				}
		}
		cout << ans << "\n";
	}
	return 0;
}