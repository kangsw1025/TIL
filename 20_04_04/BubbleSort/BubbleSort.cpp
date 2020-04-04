#include <iostream>
using namespace std;

int main()
{
	int n, cnt = 0, tmp;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int j = n - 1; j >= 1; j--) {
		for (int i = 0; i < j; i++) {
			if (arr[i] > arr[i+1]) {
				tmp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = tmp;
				cnt++;
			}
		}
	}
	cout << cnt;
	delete arr;
	return 0;
}