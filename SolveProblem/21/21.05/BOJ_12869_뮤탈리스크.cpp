#include<iostream>
#include<queue>
using namespace std;

int arr[3];

int solve() {
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {0,arr[0]},{arr[1],arr[2]} });

	while (!q.empty()) {
		int cnt = q.front().first.first;
		int first = q.front().first.second;
		int second = q.front().second.first;
		int third = q.front().second.second;
		q.pop();
		if (first <= 0 && second <= 0 && third <= 0) {
			return cnt;
		}
		if (first >= second && first >= third) {
			q.push({ {cnt + 1,first - 9}, {second - 3,third - 1} });
			q.push({ {cnt + 1,first - 9}, {second - 1,third - 3} });
		}
		else if (second >= first && second >= third) {
			q.push({ {cnt + 1,first - 3}, {second - 9,third - 1} });
			q.push({ {cnt + 1,first - 1}, {second - 9,third - 3} });
		}
		else {
			q.push({ {cnt + 1,first - 1}, {second - 3,third - 9} });
			q.push({ {cnt + 1,first - 3}, {second - 1,third - 9} });
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	cout<<solve();

	return 0;
}