#include <iostream>
#include <deque>
using namespace std;

int digit(int arr, int n)
{
	int ans;
	for (int i = 0; i < n; i++) {
		ans = arr % 10;
		arr = arr / 10;
	}
	return ans;
}

void radixSort(int *A, int  n, int k) {
	deque<int> que[10]; //que[0..9]
	int d,p;
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < n; j++) {
			d = digit(A[j], i); //A[j]의 i번째 자리의 수
			que[d].push_back(A[j]);
		}

		p = 0;
		for (int j = 0; j <= 9; j++) {
			while (!que[j].empty()) {
				A[p++] = que[j].front();
				que[j].pop_front();

			}
		}
	}
	for (int m = 0; m < n; m++) cout << A[m]<<' ';
	cout << ' ';
}

int main()
{
	int n, k, max=0;
	cin >> n >> k;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	radixSort(arr, n, k);
	delete arr;
	return 0;
}