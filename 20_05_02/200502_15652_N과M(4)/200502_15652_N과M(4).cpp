#include<iostream>
using namespace std;

int arr[9];
int n, m;

void st(int num, int c)
{
	if (c == m) {
		for (int i = 0; i < c; i++) cout << arr[i] << ' ';
		cout << "\n";
	}
	else {
		for (int i = num; i <= n; i++) {
			arr[c] = i;
			st(i, c + 1);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	st(1, 0);
	return 0;
}