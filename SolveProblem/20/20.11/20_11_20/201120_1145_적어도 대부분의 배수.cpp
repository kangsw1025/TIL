#include<iostream>
#include<algorithm>
using namespace std;

int arr[5];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 5; i++) 
		cin >> arr[i];
	sort(arr, arr + 5);
	int mid = arr[2];
	for (int i = mid; i; i++) {
		int idx = 0;
		for (int j = 0; j < 5; j++)
			if (i % arr[j] == 0) idx++;
		if (idx >= 3) {
			cout << i;
			break;
		}
	}
	return 0;
}