#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define Max 100001
int a[Max], b[Max], c[Max];
int n, ans;
vector<int> vec;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	for (int i = 1; i <= n; i++) c[b[i]] = i;
	for (int i = 1; i <= n; i++) a[i] = c[a[i]];

	for (int i = 1; i <= n; i++) {
		if (vec.empty() || vec.back() < a[i]) {
			vec.push_back(a[i]);
			ans++;
		}
		else {
			auto itr = lower_bound(vec.begin(), vec.end(), a[i]);
			*itr = a[i];
		}
	}
	cout << ans;
	return 0;
}
