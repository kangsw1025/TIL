#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int arr[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	for (int i = 0; i < m; i++) cin >> arr[i];
	sort(arr, arr + m);
	long long price, sum = 0;
	for (int i = 0; i < m; i++) {
		long long nsum = arr[i] * min((m - i),n);
		if (nsum > sum) {
			price = arr[i];
			sum = nsum;
		}
	}
	cout << price << ' ' << sum;
	return 0;
}