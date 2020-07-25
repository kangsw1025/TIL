#include<iostream>
using namespace std;

bool arr[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k, cnt = 0;
	cin >> n >> k;
	for (int i = 2; i <= n; i++) arr[i] = true;

	int i = 2;
	while (1) {
		if (arr[i] == false) i++;

		for (int j = 1; j <= n / i; j++) {
			if (arr[i * j] == true) {
				arr[i * j] = false;
				cnt++;
				if (cnt == k) {
					cout << i * j;
					return 0;
				}
			}
			
		}

	}
	return 0;
}