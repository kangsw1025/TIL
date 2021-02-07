#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
int bag[51];
vector<int> vec;

bool comp(int a, int b) {
	return a > b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> bag[i];

	sort(bag, bag + n, comp);
	cin >> m;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		vec.push_back(num);
	}

	sort(vec.begin(), vec.end(), comp);

	if (vec[0] > bag[0]) cout << -1;
	else {
		int ans = 0;
		while (1) {
			ans++;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < vec.size(); j++) {
					if (bag[i] >= vec[j]) {
						vec.erase(vec.begin() + j);
						break;
					}
				}
			}
			if (vec.empty()) break;
		}
		cout << ans;
	}
	return 0;
}