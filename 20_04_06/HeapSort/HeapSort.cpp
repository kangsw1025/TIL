#include <iostream>
#include <cmath>
using namespace std;

int cnt;
int heap[10001];

int log2(int a)
{
	if (a == 0) return 0;
	return log(a) / log(2);
}

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void makeheap(int* arr, int l)
{
	for (int i = 0; i < l; i++) heap[i + 1] = arr[i];
	int lo = log2(l);
	for (int j = lo; j >= 1; j--) {
		for (int i = l / 2; i >= pow(2, lo - j); i--) {
			if (i * 2 == l) {
				if (heap[i] < heap[i * 2]) {
					swap(heap[i * 2], heap[i]);
				}
			}
			else {
				if (heap[i * 2] <= heap[i * 2 + 1]) {
					if (heap[i] < heap[i * 2 + 1]) {
						swap(heap[i * 2 + 1], heap[i]);
					}
				}
				else {
					if (heap[i * 2] > heap[i]) {
						swap(heap[i * 2], heap[i]);
					}
				}
			}
		}
	}
	swap(heap[1], heap[l]);
}

void heapify(int* arr, int l, int n = 1)
{
	if (n > l / 2) {
		swap(arr[1], arr[l]);
		return;
	}
	else if (n * 2 == l) {
		if (arr[n] < arr[l]) {
			swap(arr[n], arr[l]);
			cnt++;
		}
		swap(arr[1], arr[l]);
		return;

	}
	else if (n * 2 + 1 == l) {
		if (arr[n] < arr[n * 2] || arr[n] < arr[2 * n + 1]) {
			if (arr[2 * n] <= arr[2 * n + 1]) {
				swap(arr[n], arr[2 * n + 1]);
				cnt++;
			}
			else {
				swap(arr[n], arr[2 * n]);
				cnt++;
			}
		}
		swap(arr[1], arr[l]);
		return;
	}

	else {
		if (arr[n] < arr[n * 2] || arr[n] < arr[2 * n + 1]) {
			if (arr[2 * n] <= arr[2 * n + 1]) {
				swap(arr[n], arr[2 * n + 1]);
				n = 2 * n + 1;
				cnt++;
			}
			else {
				swap(arr[n], arr[2 * n]);
				n = 2 * n;
				cnt++;
			}
		}
		else {
			swap(arr[1], arr[l]);
			return;
		}
		heapify(arr, l, n);
	}
}

void heapsort(int* arr, int e)
{
	makeheap(arr, e + 1);
	for (int i = e; i >= 0; i--) {
		arr[i] = heap[i + 1];
		if (i != 0) {
			heapify(heap, i);
		}
	}
}

int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) cin >> arr[i];
	heapsort(arr, n - 1);
	cout << cnt;
	delete arr;
	return 0;
}