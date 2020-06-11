#include<iostream>
using namespace std;

int arr[1001], go[1001];
bool ch[1001];
int n, l, w, we;

void solve() {
	for (int i = 0; i < n; i++) 
		if (ch[i] == true) {
			go[i]--;
			if (go[i] == 0) {
				we -= arr[i];
				ch[i] = false;
			}
		}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> l >> w;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		go[i] = l;
	}

	int time = 1, now = -1;
	while (1) {
		time++;
		if (now < n-1) {
			if (arr[now + 1] + we <= w) {
				we += arr[now + 1];
				now++;
				ch[now] = true;
			}
		}
		solve();
		if (go[n - 1] == 0) break;
	}
	cout << time;
	return 0;
}