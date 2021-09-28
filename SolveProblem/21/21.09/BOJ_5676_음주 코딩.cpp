#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int MAX = 1e5+1;
int seg[4 * MAX], n, k;

int update(int pos, int val, int node, int left, int right) {
	if (right < pos || pos < left) return seg[node];

	if (left == right) return seg[node] = val;

	int mid = (left + right) / 2;
	return seg[node] = update(pos, val, node * 2, left, mid) * update(pos, val, node * 2 + 1, mid + 1, right);
}

int query(int start, int end, int node, int left, int right) {
	if (right < start || end < left) return 1;

	if (start <= left && right <= end) return seg[node];

	int mid = (left + right) / 2;

	return query(start, end, node * 2, left, mid) * query(start, end, node * 2 + 1, mid + 1, right);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (cin >> n >> k) {
		vector<char> vec;
		for (int i = 1; i <= n; i++) {
			int num;
			cin >> num;

			if (num > 0) update(i, 1, 1, 1, n);
			else if (num == 0) update(i, 0, 1, 1, n);
			else update(i, -1, 1, 1, n);
		}

		for (int i = 0; i < k; i++) {
			char op;
			int t, v;
			cin >> op >> t >> v;

			if (op == 'C') {
				if (v > 0) update(t, 1, 1, 1, n);
				else if (v == 0) update(t, 0, 1, 1, n);
				else update(t, -1, 1, 1, n);
			}
			else {
				int rst = query(t, v, 1, 1, n);
				if (rst == 0) vec.push_back('0');
				else if (rst > 0) vec.push_back('+');
				else vec.push_back('-');
			}
		}
		for (int i = 0; i < vec.size(); i++) cout << vec[i];
		cout << "\n";
	}
	return 0;
}