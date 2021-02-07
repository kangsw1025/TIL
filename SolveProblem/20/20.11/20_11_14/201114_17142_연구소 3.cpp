#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

int n, m, blank, ans = 1e9;
int arr[51][51];
int cop[51][51];
int n_x[4] = { 0,1,0,-1 };
int n_y[4] = { 1,0,-1,0 };
bool flag;

vector<pair<int, int>> vec;
vector<int> v;

void solve(int left) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cop[i][j] = arr[i][j];

	queue<pair<int, int>> q;
	for (int i = 0; i < v.size(); i++)
		if (v[i]) {
			q.push(vec[i]);
			cop[vec[i].first][vec[i].second] = 3;
		}

	int time = 0;
	while (!q.empty()) {
		int size = q.size();
		if (!left) {
			flag = true;
			ans = min(ans, time);
			break;
		}
		time++;
		for (int i = 0; i < size; i++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int j = 0; j < 4; j++) {
				int nx = x + n_x[j];
				int ny = y + n_y[j];
				if (0 <= nx && nx < n && 0 <= ny && ny < n)
					if (!cop[nx][ny] || cop[nx][ny] == 2) {
						if (!cop[nx][ny])
							left--;
						cop[nx][ny] = 3;
						q.push({ nx, ny });
					}
			}
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) blank++;
			if (arr[i][j] == 2) vec.push_back({ i,j });
		}

	sort(vec.begin(), vec.end());
	v.resize(vec.size());
	for (int i = 0; i < v.size(); i++) v[i] = 0;
	for (int i = 0; i < m; i++) v[i] = 1;
	sort(v.begin(), v.end());

	do {
		solve(blank);
	} while (next_permutation(v.begin(), v.end()));

	if (flag)
		cout << ans;
	else cout << -1;
	return 0;
}