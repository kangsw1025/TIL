#include <iostream>
using namespace std;

void countingsort(int* A, int n) {
	int max = A[0];
	int min = A[0];
	for (int i = 1; i < n; i++) {
		if (A[i] > max) max = A[i];
		if (A[i] < min) min = A[i];
	}
	int k = max - min + 1;
	int* B = new int[k+1];
	int* C = new int[k+1];
	for (int i = 0; i <= k; i++) C[i] = 0;
	for (int j = 0; j < n; j++) C[A[j] - min]++;
	for (int i = 1; i < k; i++)
		C[i] = C[i] + C[i - 1];
	for (int i = 0; i < k; i++) cout << C[i] << ' ';
}

int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) cin >> arr[i];
	countingsort(arr, n);
	return 0;
}