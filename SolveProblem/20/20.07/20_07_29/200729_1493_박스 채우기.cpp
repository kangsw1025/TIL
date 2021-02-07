#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

bool check = true;
pair<long long,int> arr[20];
int ans;

void solve(int x, int y, int z) {
	if (!check) return;
	if (x == 0 || y == 0 || z == 0) return;

	int now = min(x, min(y, z));
	for (int i = log2(now); i >= 0; i--) {
		if (arr[i].second) {
			arr[i].second--;
			ans++;
			solve(x, y, z - arr[i].first);
			solve(arr[i].first, y - arr[i].first, arr[i].first);
			solve(x - arr[i].first, y, arr[i].first);
			return;
		}
	}
	check = false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int x, y, z,n,size,cnt;
	cin >> x >> y >> z;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> size >> cnt;
		arr[size] = make_pair(pow(2, size), cnt);
	}
	
	solve(x, y, z);
	if (check) cout << ans;
	else cout << -1;
	return 0;
}