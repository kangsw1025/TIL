#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solve(int n, vector<int> vec) {
	int idx = -1;
	int left = 0, right = vec.size() - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (n > vec[mid]) {
			idx = mid;
			left = mid + 1;
		}
		else right = mid - 1;
	}

	if (idx == -1) return 0;
	return idx + 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		int a, b, ans =0;
		cin >> a >> b;
		vector<int> vec1(a), vec2(b);
		for (int i = 0; i < a; i++)
			cin >> vec1[i];
		for (int i = 0; i < b; i++)
			cin >> vec2[i];
		sort(vec2.begin(), vec2.end());
		for (int i = 0; i < a; i++) 
			ans += solve(vec1[i], vec2);

		cout << ans << "\n";
	}
	return 0;
}