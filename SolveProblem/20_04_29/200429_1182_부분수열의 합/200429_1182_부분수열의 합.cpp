#include<iostream>
using namespace std;

int arr[21];
int a, b, cnt = 0;

void go(int n, int m)
{
	if (n == b) cnt++;
	if (m == a) return;
	for (int i = m; i < a; i++) {
		go(n + arr[i], i + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> b;
	for (int i = 0; i < a; i++) cin >> arr[i];
	
	if (b == 0) cnt = -1;

	go(0, 0);
	cout << cnt;
	return 0;
}