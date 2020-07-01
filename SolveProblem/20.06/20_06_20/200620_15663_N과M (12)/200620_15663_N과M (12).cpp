#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
vector<int> vec;
bool arr[10001];
int ans[9];

void solve(int nx, int k) {
	if (k == m) {
		for (int i = 0; i < k; i++) cout << ans[i] << ' ';
		cout << "\n";
		return;
	}

	for (int i = nx; i < vec.size(); i++) {
		ans[k] = vec[i];
		solve(i,k + 1);
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
		if (!arr[num]) {
			arr[num] = true;
			vec.push_back(num);
		}
		arr[num]++;
	}
	sort(vec.begin(), vec.end());

	for (int i = 0; i < vec.size(); i++) {
		ans[0] = vec[i];
		solve(i,1);
	}
	return 0;
}