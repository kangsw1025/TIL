#include<iostream>
#include<algorithm>
using namespace std;

int n, m, money;
int arr[10001];
int p[10001];

int find(int a) {
	if (p[a] == a) return a;
	return p[a] = find(p[a]);
}
void go(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (arr[a] > arr[b]) p[a] = b;
	else p[b] = a;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b;

	cin >> n >> m >> money;
	for (int i = 1; i <= n; i++) p[i] = i;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		if (find(a) != find(b)) go(find(a), find(b));
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (find(i) != 0) {
			ans += arr[find(i)];
			go(0, find(i));
		}
	}
	if (ans <= money) cout << ans;
	else cout << "Oh no";
	return 0;
}