#include <iostream>
#include <algorithm>
using namespace std;

int arr[20000001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		arr[m + 10000000]++;
	}
	cin >> n;
	int* nar = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> m;
		nar[i] = arr[m + 10000000];
	}
	for (int i = 0; i < n; i++) cout << nar[i] << ' ';
	return 0;
}