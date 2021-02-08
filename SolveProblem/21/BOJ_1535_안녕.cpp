#include<iostream>
#include<algorithm>
using namespace std;

int n, ans;
int energy[21], happy[21];

void solve(int idx, int left_energy, int happiness) {
	if (left_energy<=0) return;
	ans = max(ans, happiness);
	if (idx == n) return;
	for (int i = idx; i < n; i++)
		solve(i + 1, left_energy - energy[i], happiness + happy[i]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> energy[i];
	for (int i = 0; i < n; i++) cin >> happy[i];
	for (int i = 0; i < n; i++)
		solve(i + 1, 100 - energy[i], happy[i]);
	cout << ans;
	return 0;
}