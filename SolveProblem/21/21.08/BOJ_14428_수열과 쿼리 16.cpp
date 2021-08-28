#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int INF = 2e9;
struct node {
	int num = INF;
	int idx = INF;
};

int arr[100001];
vector<node> tree(400001);

bool operator < (const node& a, const node& b) {
	if(a.num==b.num) return a.idx<b.idx;
	return a.num < b.num;
}

node query(int start, int end, int node, int left, int right) {
	if (left > end || start > right) return { INF,INF };
	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	return min(query(start, mid, node * 2, left, right),
		query(mid + 1, end, node * 2 + 1, left, right));
}

node update(int start, int end, int node, int idx, int val) {
	if (idx<start || idx>end) return tree[node];
	if (start == end) return tree[node] = { val,idx };

	int mid = (start + end) / 2;

	return tree[node] = min(update(start, mid, node * 2, idx, val),
		update(mid + 1, end, node * 2 + 1, idx, val));
}

node init(int start, int end, int node) {
	if (start == end) return tree[node] = { arr[start],start };
	int mid = (start + end) / 2;
	return tree[node] = min(init(start, mid, node * 2),
		init(mid + 1, end, node * 2 + 1));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	init(0, n - 1, 1);

	cin >> m;
	for (int i = 0; i < m; i++) {
		int op, x, y;
		cin >> op >> x >> y;
		if (op == 1)
			update(0, n - 1, 1, x - 1, y);
		else
			cout << query(0, n - 1, 1, x - 1, y - 1).idx + 1 << "\n";
	}
	return 0;
}