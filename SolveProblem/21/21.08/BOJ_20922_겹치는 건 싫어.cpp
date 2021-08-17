#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;

int n, k, num, ans;
deque<int> dq;
int use[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> num;

		use[num]++;
		if (dq.empty()) dq.push_back(num);
		else {
			if (use[num] <= k) dq.push_back(num);
			else {
				int tmp = -1;
				while (tmp != num && !dq.empty()) {
					tmp = dq.front();
					dq.pop_front();
					use[tmp]--;
				}
				dq.push_back(num);
			}
		}
		int sz = dq.size();
		ans = max(ans, sz);
	}
	cout << ans;
	return 0;
}