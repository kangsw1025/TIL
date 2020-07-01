#include<iostream>
using namespace std;

int arr[10];

void count(int num, int tmp) {
	while (num) {
		arr[num % 10] += tmp;
		num = num / 10;
	}
}

void solve(int a, int b, int tmp) {
	while (a % 10 != 0 && a <= b) {
		count(a, tmp);
		a++;
	}
	if (a > b) return;

	while (b % 10 != 9 && b >= a) {
		count(b, tmp);
		b--;
	}

	int cnt = b / 10 - a / 10 + 1;
	
	for (int i = 0; i < 10; i++) arr[i] += cnt * tmp;

	solve(a / 10, b / 10, tmp * 10);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	solve(1,n,1);
	for (int i = 0; i < 10; i++) cout << arr[i] << ' ';
	return 0;
}