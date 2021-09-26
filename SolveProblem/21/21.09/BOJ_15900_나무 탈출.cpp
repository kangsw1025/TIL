#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int arr[500001];
int parent[500001];
bool visit[500001];
vector<int> v[500001];

int dfs(int n) {
	int sum = 0;
	visit[n] = true;
	if(n!=1) arr[n] = arr[parent[n]] + 1;

	bool son = false;

	for (int i = 0; i < v[n].size(); i++) {
		int next = v[n][i];
		if (!visit[next]) {
			son = true;
			parent[next] = n;
			sum += dfs(next);
		}
	}

	if (!son) sum += arr[n];

	return sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	int sum = dfs(1);

	if (sum % 2==0) cout << "No";
	else cout << "Yes";
	return 0;
}