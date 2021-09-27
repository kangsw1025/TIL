#include<iostream>
#include<map>
using namespace std;

long long sum[200001];
map<int, long long> mp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		sum[i] = sum[i - 1] + num;
	}

	long long cnt = 0;

	for (int i = 1; i <= n; i++) {
		if (sum[i] == k) cnt++;
		cnt += mp[sum[i] - k];
		mp[sum[i]]++;
	}
	cout << cnt;
	return 0;
}