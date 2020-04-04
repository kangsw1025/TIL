#include <iostream>
using namespace std;

int cnt = 0;
int num[10000];
int arr[10000];

void merge(int* ar, int s, int e)
{
	int mid = (s + e) / 2;
	int a, b;
	if (s == e) {
		return;
	}
	else {
		merge(ar, s, mid);
		merge(ar, mid+1, e);

		a = s;
		b = mid+1;
		for (int i = s; i <= e; i++) {
			if (a == mid+1)
				num[i] = ar[b++];
			else if (b == e+1)
				num[i] = ar[a++];
			else if (ar[a] >= ar[b]) {
				num[i] = ar[b++];
				cnt++;
			}
			else if (ar[a] < ar[b]) {
				num[i] = ar[a++];
				cnt++;
			}
		}
	}
	for (int i = s; i <= e; i++) ar[i] = num[i];
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	merge(arr, 0, n-1);
	cout << cnt;
	return 0;
}