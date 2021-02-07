#include<iostream>
#include<vector>
using namespace std;

vector<pair<int, int>> vec;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		vec.push_back({ i,num });
	}

	int idx = 0;
	int n2 = n;
	for (int i = 0; i < n2; i++) {
		cout << vec[idx].first << ' ';

		int move = vec[idx].second;
		if (move > 0) move--;
		vec.erase(vec.begin() + idx);

		idx += move;
		if (--n == 0) break;

		idx = (idx >= 0 ? idx : n + idx % n);
		idx %= n;
	}
	return 0;
}