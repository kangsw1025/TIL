#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int arr[101][101];
bool v[101][101];
int n_x[4] = { 0, -1, 0, 1 };
int n_y[4] = { -1, 0, 1, 0 };
int x, y, n, ans;

int go(int w, int h)
{
	int space = 1;
	v[w][h] = true;
	for (int i = 0; i < 4; i++) {
		int nx = w + n_x[i];
		int ny = h + n_y[i];
		if (nx >= 0 && nx < x && ny >= 0 && ny < y && v[nx][ny] == false && arr[nx][ny] == 0)
			space += go(nx, ny);
	}
	return space;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> x >> y >> n;
	vector<int> vec;
	vector<int>::iterator itr;
	int a, b, c, d;
	for (int k = 0; k < n; k++) {
		cin >> a >> b >> c >> d;
		for (int i = x-d; i < x-b; i++)
			for (int j = a; j < c; j++) {
				arr[i][j] = 1;
			}
	}
	for(int i = 0; i < x;i++) 
		for(int j=0;j<y;j++)
			if (v[i][j] == false && arr[i][j] == 0) {
				vec.push_back(go(i, j));
				ans++;
			}
	sort(vec.begin(), vec.end());
	cout << ans<<"\n";
	for (itr = vec.begin(); itr != vec.end(); itr++)
		cout << *itr << ' ';
	return 0;
}