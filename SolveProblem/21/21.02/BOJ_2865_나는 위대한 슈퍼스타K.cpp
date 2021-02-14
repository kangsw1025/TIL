#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

priority_queue<float, vector<float>, less<float>> user[101], cal;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cout << fixed;
	cout.precision(1);

	int n, m, k, number;
	float score, ans = 0;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) 
		for (int j = 0; j < n; j++) {
			cin >> number >> score;
			user[number].push(score);
		}
	
	for (int i = 1; i <= n; i++) cal.push(user[i].top());
	for (int i = 0; i < k; i++) {
		ans += cal.top();
		cal.pop();
	}
	cout << ans;
	return 0;
}