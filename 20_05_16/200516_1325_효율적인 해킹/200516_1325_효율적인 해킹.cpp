#include<iostream>
#include<vector>
using namespace std;

vector<int> vec[10001];
vector<int> vec2[100001];
int arr[10001];
bool v[10001];
int n, m;

void reset(int c)
{
	for (int i = 1; i <= c; i++)
		v[i] = false;
}

int solve(int num)
{
	v[num] = true;
	int cnt = 1;

	for (int i = 0; i < vec[num].size(); i++) {
		if (v[vec[num][i]] == false) {
			cnt += solve(vec[num][i]);
		}
	}

	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		vec[b].push_back(a);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		reset(n);
		arr[i] = solve(i) + 1;
		if (ans < arr[i]) ans = arr[i];
	}
	for (int i = 1; i <= n; i++)
		if (arr[i] == ans) cout << i << ' ';
	return 0;
}