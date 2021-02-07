#include<iostream>
using namespace std;

#define INF 1000000
long long arr[1500005];


void fib() {
	arr[0] = 0;
	arr[1] = 1;
	for (int i = 0; i < 1500000; i++)
		arr[i + 2] = (arr[i + 1] + arr[i]) % INF;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n;
	cin >> n;
	fib();
	cout << arr[n % 1500000];
	return 0;
}