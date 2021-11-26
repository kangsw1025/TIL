#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<map>
#include<cmath>
#include<deque>
#include<set>
#include<vector>
#include<cstdlib>
using namespace std;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
 
	int T;
	cin >> T;
	while (T--) {
		int n, max_idx = 0;
		deque<int> d, q;
		cin >> n;
 
		for (int i = 0; i < n; i++) {
			int val;
			cin >> val;
			d.push_back(val);
			if (val > d[max_idx]) max_idx = i;
		}
 
		if (max_idx != 0 && max_idx != n - 1) cout << "-1\n";
		else {
			for (int i = 0; i < n; i++) {
				if (i == 0) {
					if (d.front() > d.back()) {
						q.push_back(d.front());
						d.pop_front();
					}
					else {
						q.push_back(d.back());
						d.pop_back();
					}
				}
				else {
					if (d.front() < d.back()) {
						q.push_front(d.front());
						d.pop_front();
					}
					else {
						q.push_back(d.back());
						d.pop_back();
					}
				}
			}
			for (int i = 0; i < q.size(); i++) cout << q[i] << ' ';
			cout << "\n";
		}
	}
 
	return 0;
}