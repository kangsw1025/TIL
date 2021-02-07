#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
vector<int> vec;
int arr[10001];
int ans[9];

void solve(int k) {
	if (k == m) {
		for (int i = 0; i < k; i++) cout << ans[i]<<' ';
		cout << "\n";
		return;
	}

	for (int i = 0; i < vec.size(); i++) {
		if (arr[vec[i]]) {
			ans[k] = vec[i];
			arr[vec[i]]--;
			solve(k + 1);
			arr[vec[i]]++;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int num;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (!arr[num]) vec.push_back(num);
		arr[num]++;
	}
	sort(vec.begin(), vec.end());

	for (int i = 0; i < vec.size(); i++) {
		ans[0] = vec[i];
		arr[vec[i]]--;
		solve(1);
		arr[vec[i]]++;
	}
	return 0;
}