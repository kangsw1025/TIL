#include<iostream>
#include<algorithm>
using namespace std;

int arr[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	sort(arr + 1, arr + n + 1);

	int T;
	cin >> T;
	while(T--) {
		int l = 1, r = n, val;
		cin >> val;
		
		bool is = false;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (arr[mid] == val) {
				is = true;
				break;
			}
			else {
				if (arr[mid] < val) l = mid + 1;
				else r = mid - 1;
			}
		}

		if (is) cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}