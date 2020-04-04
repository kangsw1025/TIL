#include <iostream>
using namespace std;

int main()
{
	int n, max, cnt = 0;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)cin >> arr[i];
	for (int j = n - 1; j >= 1; j--) {
		max = 0;
		for (int i = 1; i <= j; i++) {
			if (arr[i] > arr[max]) {
				max = i;
				cnt++;
			}
		}
		if (arr[j] < arr[max]) {
			int tmp;
			tmp = arr[max];
			arr[max] = arr[j];
			arr[j] = tmp;
		}
	}
	cout << cnt;
	return 0;
}