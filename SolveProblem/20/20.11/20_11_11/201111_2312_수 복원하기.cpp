#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int arr[100001];

void solve(int num) {
	vector<int> vec;
	int idx = 2;
	while (num != 1) {
		if (num % idx == 0) {
			if (arr[idx] == 0) {
				vec.push_back(idx);
				arr[idx]++;
			}
			else arr[idx]++;
			num /= idx;
		}
		else idx++;
	}
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << ' ' << arr[vec[i]] << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int num;
		cin >> num;

		fill(arr, arr + num + 1, 0);
		solve(num);
	}
	return 0;
}
