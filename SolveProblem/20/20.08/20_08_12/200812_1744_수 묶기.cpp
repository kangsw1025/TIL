#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<int, vector<int>, greater<int>> s_z;
	priority_queue<int, vector<int>, less<int>> b_z;
	int n, zero = 0;
	long long ans = 0;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (num < 0) s_z.push(num);
		else if (num == 1) ans++;
		else if (num > 1) b_z.push(num);
		else zero++;
	}
	int check = 0, num = 1;
	while (!s_z.empty()) {
		check++;
		num *= s_z.top();
		s_z.pop();
		if (check == 2) {
			check = 0;
			ans += num;
			num = 1;
		}
	}
	if (!zero && check) ans += num;
	check = 0, num = 1;
	while (!b_z.empty()) {
		check++;
		num *= b_z.top();
		b_z.pop();
		if (check == 2) {
			check = 0;
			ans += num;
			num = 1;
		}
	}
	if (check) ans += num;

	cout << ans;
	return 0;
}