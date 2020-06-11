#include<iostream>
using namespace std;

int array[10000];
int cnt;

int partition(int* A, int p, int r)
{
	int tmp;
	int x = A[r];
	int i = p - 1;
	for (int j = p; j <= r - 1; j++)
		if (A[j] <= x) {
			tmp = A[++i];
			A[i] = A[j];
			A[j] = tmp;
			cnt++;
		}
	tmp = A[r];
	A[r] = A[i + 1];
	A[i + 1] = tmp;
	cnt++;
	return i + 1;
}

void quicksort(int* ar, int s, int e)
{
	int ad;
	if (s < e) {
		ad = partition(ar, s, e);
		quicksort(ar,s,ad-1);
		quicksort(ar, ad+1, e);
	}
}



int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) cin >> arr[i];
	quicksort(arr, 0, n - 1);
	cout << cnt;
	delete arr;
	return 0;
}