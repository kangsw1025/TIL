#include <iostream>
using namespace std;

void lotto(int *sa, int* arr, int h, int m, int cnt)
{
	sa[cnt] = arr[h];
	cnt++;
	if (cnt == 6) {
		for (int i = 0; i < 6; i++) cout << sa[i] << ' ';
		cout << "\n";
		return;
	}
	for (int i = h + 1; i < m; i++) lotto(sa, arr, i, m, cnt);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	
	while (1) {
		cin >> n;
		int sa[6];
		if (n == 0) break;

		int* arr = new int[n];
		for (int i = 0; i < n; i++) cin >> arr[i];

		for(int i=0;i<n-3;i++)
			lotto(sa, arr, i, n, 0);
		cout << "\n";
		delete arr;
	}
}