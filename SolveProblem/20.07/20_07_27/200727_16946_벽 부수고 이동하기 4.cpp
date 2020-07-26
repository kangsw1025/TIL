#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int x, y;
char arr[1001][1001];
int ans[1001][1001];
int zero_c[1001][1001];
int zero_count[1000001];
bool check[1001][1001];
int n_x[4] = { 0,1,0,-1 };
int n_y[4] = { 1,0,-1,0 };

void zero_s(int i, int j, int z) {
	zero_c[i][j] = z;
	zero_count[z]++;
	
	for (int k = 0; k < 4; k++) {
		int nx = i + n_x[k];
		int ny = j + n_y[k];
		if (nx >= 0 && nx < x && ny >= 0 && ny < y && !check[nx][ny] && arr[nx][ny] == '0') {
			check[nx][ny] = true;
			zero_s(nx, ny, z);
		}
	}
}

int solve(int i, int j) {
	int cnt = 1;

	vector<int> v;

	for (int k = 0; k < 4; k++) {
		int nx = i + n_x[k];
		int ny = j + n_y[k];
		if (nx >= 0 && nx < x && ny >= 0 && ny < y && arr[nx][ny] == '0')
			v.push_back(zero_c[nx][ny]);	
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 0; i < v.size(); i++) cnt += zero_count[v[i]];

	return cnt%10;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> x >> y;
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++) cin >> arr[i][j];
	
	int zero = 1;

	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			if (!check[i][j] && arr[i][j]=='0') {
				check[i][j] = true;
				zero_s(i, j, zero++);
			}
			
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (arr[i][j] == '1')
				cout << solve(i, j);
			else cout << 0;
		}
		cout << "\n";
	}
	
	return 0;
}