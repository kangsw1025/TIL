#include<iostream>
using namespace std;

int main()
{
	int n, tmp, cnt = 0, key;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 1; i < n; i++) {
		key = arr[i];
		for (int j = i - 1; j >= 0; j--) {
			cnt++;
			if (j == 0 && arr[j] > key) {
				cnt++;
				arr[j + 1] = arr[j];
				arr[j] = key;
			}
			else if (arr[j] > key) {
				arr[j + 1] = arr[j];
			}
			else if (arr[j] <= key) {
				arr[j + 1] = key;
				break;
			}
		}
	}
	cout << cnt;
	delete arr;
	return 0;
}
