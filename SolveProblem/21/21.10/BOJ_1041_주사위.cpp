#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int arr[6];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	vector<int> v,v2;
	cin >> n;
	for (int i = 0; i < 6; i++) cin >> arr[i];

	if (n == 1) {
		sort(arr, arr + 6);
		cout << arr[0] + arr[1] + arr[2] + arr[3] + arr[4];
		return 0;
	}

	for(int i=0;i<5;i++)
		for (int j = i + 1; j < 6; j++) {
			if (i + j == 5) continue;
			v.push_back(arr[i] + arr[j]);
		}
	sort(v.begin(), v.end());

	for(int i=0;i<4;i++)
		for (int j = i + 1; j < 5; j++) {
			if (i + j == 5) continue;
			for (int k = j + 1; k < 6; k++) {
				if (j + k == 5 || i + k == 5) continue;
				v2.push_back(arr[i] + arr[j] + arr[k]);
			}
		}
	sort(v2.begin(), v2.end());
	sort(arr, arr + 6);
	long long o_1 = arr[0];
	long long o_2 = v[0];
	long long o_3 = v2[0];

	long long one, third = 4, two = (2*n-3) * 4;
	one = pow(n,2) * 5LL - (third * 3 + two * 2);
	cout << o_1 * one + o_2 * two + o_3 * third;
	return 0;
}