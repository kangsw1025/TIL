#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int arr[101][100001];
int n, m;

vector<pair<int, int>> vec;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j <= m; j++) arr[i][j] = 0;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		vec.push_back(make_pair(a, b));
	}
	sort(vec.begin(), vec.end());
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= m; j++) {
			if (i == 0) {
				if (vec[i].first <= j) arr[i][j] = vec[i].second;
				continue;
			}
			if (vec[i].first <= j) arr[i][j] = max(arr[i - 1][j], vec[i].second + arr[i - 1][j-vec[i].first]);
			else arr[i][j] = arr[i - 1][j];
		}
	}
	cout << arr[n - 1][m];
	return 0;
}