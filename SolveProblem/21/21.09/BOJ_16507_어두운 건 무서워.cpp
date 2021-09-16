#include<iostream>
using namespace std;

long long arr[1001][1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int x, y, t;
	cin >> x >> y >> t;
	for(int i=1;i<=x;i++)
		for (int j = 1; j <= y; j++) {
			int val;
			cin >> val;
			arr[i][j] = arr[i][j - 1] + arr[i - 1][j] - arr[i - 1][j - 1] + val;
		}

	while (t--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		cout << (arr[x2][y2] - arr[x2][y1 - 1] - arr[x1 - 1][y2] + arr[x1 - 1][y1 - 1])/((x2-x1+1) * (y2-y1+1)) << "\n";
	}
	return 0;
}