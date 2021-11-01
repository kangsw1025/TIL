#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

int cnt[101], last[101];
set<int> st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;
	for(int i=1;i<=k;i++) {
		int val;
		cin >> val;

		auto itr = st.find(val);
		if (itr != st.end()) {
			cnt[val]++;
			continue;
		}

		if (st.size() < n) {
			st.insert(val);
			cnt[val]++;
			last[val] = i;
			continue;
		}

		int eraser, op = 1001;

		for (auto it : st) {
			if (cnt[it] < op) {
				eraser = it;
				op = cnt[it];
			}
			else if (cnt[it] == op) {
				eraser = (last[it] > last[eraser]) ? eraser : it;
			}
		}

		st.erase(eraser);
		cnt[eraser] = 0;
		last[eraser] = 0;
		st.insert(val);
		cnt[val]++;
		last[val] = i;
	}

	for (auto itr : st) cout << itr << ' ';
	return 0;
}