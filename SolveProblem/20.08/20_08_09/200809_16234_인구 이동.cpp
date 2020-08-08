#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int n, mi, ma;
int people;
int arr[51][51];
bool check[51][51];
vector<pair<int, int>> vec;
int n_x[4] = { 0,1,0,-1 };
int n_y[4] = { 1,0,-1,0 };

void reset() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			check[i][j] = false;
}

void solve(int w, int h) {
	for (int i = 0; i < 4; i++) {
		int nx = w + n_x[i];
		int ny = h + n_y[i];

		int dif = abs(arr[w][h] - arr[nx][ny]);
		if (nx >= 0 && nx < n && ny >= 0 && ny < n && dif >=mi && dif <=ma && !check[nx][ny]) {
			check[nx][ny] = true;
			vec.push_back(make_pair(nx, ny));
			people += arr[nx][ny];
			solve(nx, ny);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> mi >> ma;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) cin >> arr[i][j];

	int ans = 0;
	while(1) {
		reset();
		bool change = false;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				if (!check[i][j]) {
					check[i][j] = true;
					people = arr[i][j];

					vec.clear();
					vec.push_back(make_pair(i, j));
					solve(i, j);

					if (vec.size() >= 2) {
						change = true;

						for (int i = 0; i < vec.size(); i++)
							arr[vec[i].first][vec[i].second] = people / vec.size();
					}
				}
			}
		if (change) ans++;
		else break;
	}
	cout << ans;
	return 0;
}