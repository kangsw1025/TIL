#include<iostream>
#include<algorithm>
using namespace std;

long long arr[100001];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	long long ans, before, cnt = 0, max_cnt = 0;;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			before = arr[i];
			cnt++;
		}
		else {
			if (arr[i] == before) cnt++;
			else {
				if (max_cnt < cnt) {
					max_cnt = cnt;
					ans = before;
				}
				cnt = 1;
				before = arr[i];
			}
		}
	}
	if (max_cnt < cnt) ans = before;
	cout << ans;
	return 0;
}