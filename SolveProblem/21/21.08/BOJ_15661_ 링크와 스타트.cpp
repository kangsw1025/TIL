#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int arr[21][21];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, rst = 2e9;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) cin >> arr[i][j];

	for (int k = 1; k < n - 1; k++) {
		vector<int> v;
		for (int i = 0; i < k; i++) v.push_back(0);
		for (int i = 0; i < n - k; i++) v.push_back(1);

		do {
			int asum = 0, bsum = 0;

			vector<int> a, b;
			for (int i = 0; i < n; i++) {
				if (v[i] == 0) a.push_back(i);
				else b.push_back(i);
			}

			for (int i = 0; i < a.size(); i++)
				for (int j = i + 1; j < a.size(); j++)
					asum += arr[a[i]][a[j]] + arr[a[j]][a[i]];

			for (int i = 0; i < b.size(); i++)
				for (int j = i + 1; j < b.size(); j++)
					bsum += arr[b[i]][b[j]] + arr[b[j]][b[i]];

			rst = min(rst, abs(asum - bsum));
		} while (next_permutation(v.begin(), v.end()));
	}
	cout << rst;
	return 0;
}