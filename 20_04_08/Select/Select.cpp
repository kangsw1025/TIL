#include<iostream>
using namespace std;

int cnt;

void swap(int* a, int* b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
	
}

int partition(int* A, int p, int r) {
	int x = A[r];
	int i = p - 1;
	for (int j = p; j <= r - 1; j++)
		if (A[j] <= x) {
			swap(A[++i], A[j]);
			cnt++;
		}
	swap(A[i + 1], A[r]);
	cnt++;
	return i + 1;
}

int select(int* A, int p, int r, int i)
{
	if (p == r) return A[p];
	int q = partition(A, p, r); //QuickSort에서 partition과 같음
	int k = q - p + 1;
	if (i < k) return select(A, p, q - 1, i);
	else if (i > k) return select(A, q + 1, r, i - k);
	else return A[q]; //i == k
}

int main()
{
	int n, m;
	cin >> n >> m;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) cin >> arr[i];
	int ans = select(arr, 0, n - 1, m);
	cout << cnt;
	delete arr;
	return 0;
}