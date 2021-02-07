#include<iostream>
#include<algorithm>
using namespace std;

pair<int, int> arr[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int cnt = 1;
		cin >> m;
		for (int j = 0; j < m; j++) {
			cin >> arr[j].first >> arr[j].second;
		}
		sort(arr, arr + m);
		
		int intgrade = arr[0].second;
		for (int j = 1; j < m; j++) {
			if (arr[j].second < intgrade) {
				cnt++;
				intgrade = arr[j].second;
			}
		}

		cout << cnt << "\n";
	}
	return 0;
}