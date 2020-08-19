#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> vec;

class segment {
public:
	int n;
	vector<int> v;
	segment(vector<int>& vec) {
		n = vec.size();
		v.resize(n * 4);
		init(vec, 0, n - 1, 1);
	}
	int init(vector<int>& vec, int left, int right, int node) {
		if (left == right) return v[node] = vec[left];

		int mid = (left + right) / 2;
		int left_tree = init(vec, left, mid, node * 2);
		int right_tree = init(vec, mid + 1, right, node * 2 + 1);
		return v[node] = min(left_tree, right_tree);
	}
	int query(int left, int right, int node, int start, int end) {
		if (right < start || end < left) return 2e9;
		if (left <= start && end <= right) return v[node];

		int mid = (start + end) / 2;
		return min(query(left, right, node * 2, start, mid), query(left, right, node * 2 + 1, mid + 1, end));
	}
	int query(int l, int r) {
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
		cout << tree.query(a, b) << "\n";
	}
	return 0;
}