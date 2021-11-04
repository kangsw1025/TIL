#include<iostream>
using namespace std;

int arr[6];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, idx=0, cnt=0;
	cin >> n;
	for (int T = 1; T <= n; T++) {
		int sum = 0;
		for (int i = 1; i <= 5; i++) cin >> arr[i];

		for(int i=1;i<=3;i++)
			for(int j=i+1;j<=4;j++)
				for (int k = j + 1; k <= 5; k++) {
					int nsum = arr[i] + arr[j] + arr[k];
					nsum %= 10;

					sum = max(sum, nsum);
				}

		if (sum >= cnt) {
			idx = T;
			cnt = sum;
		}
	}

	cout << idx;
	return 0;
}