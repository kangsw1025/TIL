#include <iostream>
#include<cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b;
	cin >> a >> b;
	int* arr = new int[a];
	int max = 0;
	int sum;
	for (int i = 0; i < a; i++) cin >> arr[i];
	for (int i = 0; i < a - 2; i++) {
		for (int j = i + 1; j < a - 1; j++) {
			for (int k = j + 1; k < a; k++) {
				sum = arr[i] + arr[j] + arr[k];
				if (sum <= b && abs(b - max) > abs(b - sum)) max = sum;
			}
		}
	}
	cout << max;
	return 0;
}