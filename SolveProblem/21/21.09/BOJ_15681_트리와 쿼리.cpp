#include<iostream>
#include<vector>
using namespace std;

vector<int> vec[100001];
int arr[100001];
bool visit[100001];

int init(int node) {
	arr[node] = 1;
	visit[node] = true;
	for (int i = 0; i < vec[node].size(); i++) {
		int next = vec[node][i];

		if (!visit[next]) arr[node] += init(next);
	}

	return arr[node];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, r, q;
	cin >> n >> r >> q;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}

	init(r);

	for (int i = 0; i < q; i++) {
		int query;
		cin >> query;
		cout << arr[query] << "\n";
	}
	return 0;
}