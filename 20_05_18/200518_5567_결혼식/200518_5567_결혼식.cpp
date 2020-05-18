#include<iostream>
#include<vector>
using namespace std;

vector<int> vec[501];
bool v[501];
int n, m;

int solve()
{
	int cnt = 0;
	v[1] = true;

	for (int i = 0; i < vec[1].size(); i++) {
		int x = vec[1][i];
		if (v[x] == false) {
			v[x] = true;
			cnt++;
		}
		for (int j = 0; j < vec[x].size(); j++) {
			if (v[vec[x][j]] == false) {
				cnt++;
				v[vec[x][j]] = true;
			}
		}
	}

	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	cout << solve();
	return 0;
}