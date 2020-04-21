#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<pair<int, pair<float, float>>> vec;
	int n;
	int p, l, r;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p >> l >> r;
		vec.push_back(make_pair(p, make_pair((l*2+1)/2, (r*2-1)/2)));
	}
	sort(vec.begin(), vec.end());
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += vec[i].first * 2;
		bool left = false, right = false;
		for (int j = i-1; j >= 0; j--) {
			if (left == false && vec[i].second.first >= vec[j].second.first && vec[i].second.first <= vec[j].second.second) {
				sum -= vec[j].first;
				left = true;
			}
			if (right == false && vec[i].second.second >= vec[j].second.first && vec[i].second.second <= vec[j].second.second) {
				sum -= vec[j].first;
				right = true;
			}
			if (left == true && right == true) break;
		}
	}
	cout << sum;
	return 0;
}