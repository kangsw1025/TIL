#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> vec;

int ans[2501];
char arr[51][51];
int ar[51][51];
bool v[51][51];
int n_x[4] = { 0,1,0,-1 };
int n_y[4] = { 1,0,-1,0 };
int x, y;
int cnt;

void solve(int w, int h)
{
	v[w][h] = true;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int nx = w + n_x[i];
		int ny = h + n_y[i];
		if (nx >= 0 && nx < x && ny >= 0 && ny < y && v[nx][ny] == false && arr[nx][ny] == '1')
			solve(nx, ny);
	}
}

void copy(int w, int h, int num)
{
	v[w][h] = true;
	ar[w][h] = num;
	for (int i = 0; i < 4; i++) {
		int nx = w + n_x[i];
		int ny = h + n_y[i];
		if (nx >= 0 && nx < x && ny >= 0 && ny < y && ar[nx][ny]==0 && arr[nx][ny] == '1')
			copy(nx, ny, num);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> x >> y;
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++) cin >> arr[i][j];

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cnt = 0;
			if (arr[i][j] == '1' && v[i][j] == false) {
				solve(i, j);
				copy(i, j, cnt);
				vec.push_back(cnt);
			}
		}
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i++) {
		ans[vec[i]] = i + 1;
	}

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++)
			cout << ans[ar[i][j]];
		cout << "\n";
	}
	return 0;
}