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
		return v[node] = max(left_tree, right_tree);
	}
	int query(int left, int right, int node, int start, int end) {
		if (right<start || left>end) return 0;
		if (left <= start && right >= end) return v[node];

		int mid = (start + end) / 2;
		return max(query(left, right, node * 2, start, mid), query(left, right, node * 2 + 1, mid + 1, end));
	}
	int query(int l, int r) {
		return query(l , r , 1, 0, n - 1);
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

	for (int i = m - 1; i < n - m + 1; i++)
		cout << tree.query(i - m + 1, i + m - 1)<<' ';
	
	return 0;
}