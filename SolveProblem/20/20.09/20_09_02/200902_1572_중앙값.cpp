#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define MAX 65536
#define MAX_N 250001

vector<int> v,vec;
int n, k, sz;
long long ans;

int update(int idx, int val, int node, int left, int right) {
	if (idx > right || idx < left) return v[node];

	if (left == right) return v[node] += val;
	int mid = (left + right) / 2;
	return v[node] = update(idx, val, node * 2, left, mid) + update(idx, val, node * 2 + 1, mid + 1, right);
}

int query(int val, int node, int left, int right) {
	int mid = (left + right) / 2;
	if (left == right) return left;
	if (v[node * 2] >= val) return query(val, node * 2, left, mid);
	return query(val - v[node * 2], node * 2 + 1, mid + 1, right);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	vec.resize(MAX_N);
	v.resize(MAX_N * 4);
	for (int i = 0; i < n; i++) {
		cin>>vec[i];
	}

	for (int i = 0; i < k - 1; i++) update(vec[i], 1, 1, 0, MAX - 1);

	for (int i = k - 1; i < n; i++) {
		update(vec[i], 1, 1, 0, MAX - 1);
		ans += query((k + 1) / 2, 1, 0, MAX - 1);
		update(vec[i - k + 1], -1, 1, 0, MAX - 1);
	}
	cout << ans;
	return 0;
}
