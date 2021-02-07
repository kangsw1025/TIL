#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int arr[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);

	int i = 0, j = n - 1;
	int ans = 2000000001;
	pair<int, int> ans_pair;
	while (i < j) {
		int dif = arr[j] + arr[i];
		if (ans > abs(dif)) {
			ans = abs(dif);
			ans_pair = make_pair(i, j);
		}
		if (dif < 0) i++;
		else if (dif > 0) j--;
		else if (dif == 0) {
			break;
		}
	}
	cout << arr[ans_pair.first]<<' '<<arr[ans_pair.second];
	return 0;
}