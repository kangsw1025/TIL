#include<iostream>
#include<algorithm>
using namespace std;

int aar[500001];
int bar[500001];
int a, b;

void check(int n, int* arr, int s, int e)
{
	if (s == e) {
		if (n == arr[e]) cout << "1 ";
		else cout << "0 ";
		return;
	}
	int mid = (s + e) / 2;
	if (n > arr[mid]) check(n, arr, mid + 1, e);
	else if (n < arr[mid]) check(n, arr, s, mid);
	else if (n == arr[mid]) {
		cout << "1 ";
		return;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> a;
	for (int i = 0; i < a; i++) cin >> aar[i];
	cin >> b;
	for (int i = 0; i < b; i++) cin >> bar[i];
	sort(aar, aar + a);
	for (int i = 0; i < b; i++) check(bar[i], aar, 0, a - 1);
	return 0;
}