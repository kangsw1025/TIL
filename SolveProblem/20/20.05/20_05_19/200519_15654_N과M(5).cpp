#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int arr[9];
int ans[9];
bool v[9];

void solve(int a, int b)
{
	ans[b] = a;
	if (b == m) {
		for (int i = 1; i <= m; i++)
			cout << ans[i] << ' ';
		cout << "\n";
	}
	else {
		for (int i = 0; i < n; i++) {
			if (v[i] == false) {
				v[i] = true;
				solve(arr[i], b + 1);
				v[i] = false;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		v[i] = true;
		solve(arr[i], 1);
		v[i] = false;
	}
	return 0;
}