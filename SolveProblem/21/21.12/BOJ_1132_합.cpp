#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int arr[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<int, vector<int>, greater<int>> q;
	vector<pair<int, pair<int,int>>> v;

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		v.push_back({ b,{1,a} });
		v.push_back({ c,{0,a} });
	}

	sort(v.begin(), v.end());

	int ans = 0;
	for (auto itr : v) {
		if (itr.second.first == 0) {
			q.push(arr[itr.second.second]);
		}
		else {
			if (q.empty()) {
				arr[itr.second.second] = ++ans;
			}
			else {
				arr[itr.second.second] = q.top();
				q.pop();
			}
		}
	}

	cout << ans << "\n";
	for (int i = 1; i <= n; i++) cout << arr[i] << "\n";
	
	return 0;
}