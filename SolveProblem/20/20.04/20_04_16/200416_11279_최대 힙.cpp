#include<iostream>
using namespace std;

int arr[100001];

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void mahe(int* arr, int cnt)
{
	int n = 1;
	while (n <= cnt/2) {
		if (arr[n] < arr[2 * n] || arr[n] < arr[2 * n + 1]) {
			if (arr[2 * n + 1] >= arr[2 * n]) {
				swap(arr[n], arr[2 * n + 1]);
				n = 2 * n + 1;
			}
			else {
				swap(arr[n], arr[2 * n]);
				n = 2 * n;
			}
		}
		else break;
	}
}

void ins(int* arr, int cnt) {
	while (cnt != 1) {
		if (arr[cnt] > arr[cnt / 2]) {
			swap(arr[cnt], arr[cnt / 2]);
			cnt = cnt / 2;
		}
		else break;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, cnt = 1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		if (m == 0) {
			if (cnt == 1) cout << "0\n";
			else {
				cout << arr[1]<<"\n";
				swap(arr[1], arr[cnt - 1]);
				arr[cnt - 1] = 0;
				cnt--;
				mahe(arr, cnt);
			}
		}
		else {
			arr[cnt++] = m;
			ins(arr, cnt - 1);
		}
	}

	return 0;
}