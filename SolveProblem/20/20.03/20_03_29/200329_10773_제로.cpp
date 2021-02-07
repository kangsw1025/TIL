#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, num, c = 0, sum = 0;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num == 0 && c == 0) continue;
		else if (num == 0) {
			arr[c - 1] = 0;
			c--;
		}
		else arr[c++] = num;
	}
	for (int i = 0; i < c; i++) sum += arr[i];
	cout << sum;
	return 0;
}