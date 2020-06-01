#include<iostream>
#include<algorithm>
using namespace std;

int arr[8];
int ans[8];
int n, m;

void go(int l, int num)
{
	if (l == m) {
		for (int i = 0; i < l; i++) cout << ans[i] << ' ';
		cout << "\n";
	}
	else
		for (int i = num; i < n; i++) {
			ans[l] = arr[i];
			go(l + 1, i);
		}
}

void solve()
{
	for (int i = 0; i < n; i++) {
		ans[0] = arr[i];
		go(1, i);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);

	solve();
	return 0;
}