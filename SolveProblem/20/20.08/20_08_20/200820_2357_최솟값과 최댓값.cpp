#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> vec;

class segment {
public:
	int n;
	vector<pair<int,int>> v;
	segment(vector<int>& vec) {
		n = vec.size();
		v.resize(n * 4);
		init(vec, 0, n - 1, 1);
	}
	pair<int,int> init(vector<int>& vec, int left, int right, int node) {
		if (left == right) return v[node] = make_pair(vec[left], vec[left]);

		int mid = (left + right) / 2;
		pair<int, int> left_tree = init(vec, left, mid, node * 2);
		pair<int, int> right_tree = init(vec, mid + 1, right, node * 2 + 1);
		return v[node] = make_pair(min(left_tree.first, right_tree.first), max(left_tree.second, right_tree.second));
	}
	pair<int, int> query(int left, int right, int node, int start, int end) {
		if (right<start || left>end) return make_pair(2e9,-2e9);
		if (left <= start && right >= end) return v[node];

		int mid = (start + end) / 2;
		pair<int, int> l = query(left, right, node * 2, start, mid);
		pair<int, int> r = query(left, right, node * 2 + 1, mid + 1, end);
		return make_pair(min(l.first, r.first), max(l.second, r.second));
	}
	pair<int, int> query(int l, int r) {
		return query(l - 1, r - 1, 1, 0, n - 1);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		vec.push_back(num);
	}

	segment tree(vec);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		pair<int, int> q = tree.query(a, b);
		cout << q.first << ' ' << q.second << "\n";
	}
	return 0;
}