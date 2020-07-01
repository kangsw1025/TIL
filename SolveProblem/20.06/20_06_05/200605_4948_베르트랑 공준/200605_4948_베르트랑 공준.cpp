#include<iostream>
#include<cmath>
using namespace std;

int arr[246913];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 2; i <= 246912; i++) {
		bool check = true;
		for (int j = 2; j <= sqrt(i); j++) {
			if (i % j == 0) {
				check = false;
				break;
			}
		}
		if (check) arr[i] = arr[i - 1] + 1;
		else arr[i] = arr[i - 1];
	}

	int n;
	while (1) {
		cin >> n;
		if (n == 0) break;
		cout << arr[2 * n] - arr[n] << "\n";
	}
	return 0;
}