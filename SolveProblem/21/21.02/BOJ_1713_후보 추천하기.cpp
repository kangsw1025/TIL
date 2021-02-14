#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int point[101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k, num;
	cin >> n >> k;
	vector<pair<int, int>> vec(n);

	for (int i = 0; i < k; i++) {
		cin >> num;
		point[num]++;

		bool change = true;
		for (int j = 0; j < n; j++) {
			if (vec[j].second == 0) {
				vec[j].second = num;
				vec[j].first = i;
				change = false;
				break;
			}
			else if (vec[j].second == num) {
				change = false;
				break;
			}
		}

		if (change) {
			int idx = 0;
			for (int j = 1; j < n; j++) {
				if (point[vec[j].second] == point[vec[idx].second]) {
					if (vec[j].first < vec[idx].first) idx = j;
				}
				else if (point[vec[j].second] < point[vec[idx].second])
					idx = j;
			}

			point[vec[idx].second] = 0;
			vec[idx].first = i;
			vec[idx].second = num;
		}
	}

	vector<int> picture;
	for (int i = 0; i < n; i++) picture.push_back(vec[i].second);
	sort(picture.begin(), picture.end());
	for (int i = 0; i < n; i++) cout << picture[i] << ' ';
	return 0;
}