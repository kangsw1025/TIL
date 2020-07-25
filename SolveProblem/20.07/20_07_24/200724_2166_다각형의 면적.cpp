#include<iostream>
#include<cmath>
using namespace std;

int n;
pair<double, double> arr[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;
	arr[n].first = arr[0].first;
	arr[n].second = arr[0].second;

	long double ans = 0;
	for (int i = 0; i < n; i++)
		ans += (arr[i].first + arr[i + 1].first) * (arr[i].second - arr[i + 1].second) / 2;

	cout << fixed;
	cout.precision(1);
	cout << fabs(ans);
	return 0;
}