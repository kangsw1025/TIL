#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int,int>> v;
bool cmp(pair<int, int> f, pair<int, int> s) {
	if (f.first == s.first) return f.second > s.second;
	return f.first < s.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ b,c });
	}

	sort(v.begin(), v.end(), cmp);
	v.erase(unique(v.begin(), v.end()), v.end());
	vector<int> vec;

	for (int i = 0; i < v.size(); i++) {
		int l = 0, r = vec.size();
		int mid = (l + r) / 2;
		while (l < r) {
			mid = (l + r) / 2;
			if (vec[mid] < v[i].second) r = mid;
			else l = mid + 1;
		}
		if (l == vec.size()) vec.push_back(v[i].second);
		else vec[l] = v[i].second;
	}

	cout << vec.size();
	return 0;
}