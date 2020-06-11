#include<iostream>
using namespace std;

void swap(int* a, int* b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int cel(int a, int b)
{
	if (a % b == 0) return a / b;
	else return a / b + 1;
}

int partition(int* A, int p, int r) {
	int x = A[r];
	int i = p - 1;
	for (int j = p; j <= r - 1; j++)
		if (A[j] <= x)
			swap(A[++i], A[j]);
	swap(A[i + 1], A[r]);
	return i + 1;
}


int partitionByMedian(int* A, int p, int r, int M) {
	// i = A[p..r]에서 M의 인덱스를 찾아 반환
	int i;
	for (int x = p; x <= r; x++) {
		if (A[x] == M) {
			i = x;
			break;
		}
	}
	swap(A[i], A[r]); // M의 인덱스의 값과 마지막 원소와 교환

	//아래와 같은 방법으로 partition 수행
	return partition(A, p, r);
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

int ls(int* A, int p, int r, int i)
{
	int Barr[2000];
	if (r - p <= 4) return select(A, p, r, i);

	int bsize = cel(r - p + 1, 5);
	int bi = 0;
	
	for (int n = p; n <= r; n += 5) {
		if (r - n < 4) {
			Barr[bi] = select(A, n, r, (r - n) / 2 + 1);

		}
		else Barr[bi++] = select(A, n, n + 4, 3);
	}

	int m = ls(Barr, 0, bsize - 1, cel(bsize, 2));
	cout << m << endl;

	int q = partitionByMedian(A, p, r, m);
	int k = q - p + 1;

	if (i < k) return ls(A, p, q - 1, i);
	else if (i == k) return A[q];
	else return ls(A, q + 1, r, i - k);

}


int main()
{
	int n, idx;
	int arr[10000];
	cin >> n >> idx;
	for (int i = 0; i < n; i++) cin >> arr[i];
	ls(arr, 0, n - 1, idx);
	return 0;
}