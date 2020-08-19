#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class segment {
public:
	int n;
	vector<long long> sum;
	segment(vector<long long>& vec) {
		n = vec.size();
		sum.resize(n * 4);
		fill(sum.begin(), sum.end(), 0);
	}
	long long query(int left, int right, int node, int start, int end) {
		if (right<start || left>end) return 0;
		if (left <= start && right >= end) return sum[node];

		int mid = (start + end) / 2;
		return query(left, right, node * 2, start, mid) + query(left, right, node * 2 + 1, mid + 1, end);
	}
	long long query(int l, int r) {
		return query(l , r , 1, 0, n-1);
	}
	long long update(int idx, long long newval, int node, int start, int end) {
		if (idx<start || idx>end) return sum[node];
		if (start == end) return sum[node] = newval;

		int mid = (start + end) / 2;
		return sum[node] = update(idx, newval, node * 2, start, mid) + update(idx, newval, node * 2 + 1, mid + 1, end);
	}
	long long update(int idx, long long newval) {
		return update(idx , newval, 1, 0, n-1);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<long long> vec;
	
	for (int i = 0; i <= n; i++) vec.push_back(0);

	segment tree(vec);

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0) {
			if (b > c) swap(b, c);
			cout << tree.query(b, c) << "\n";
		}
		else 
			tree.update(b, c);
	}
	return 0;
}