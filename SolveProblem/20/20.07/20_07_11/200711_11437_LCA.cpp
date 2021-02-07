#include<iostream>
#include<vector>
using namespace std;

int arr[50001];
int height[50001];
bool ch[50001];
vector<int> v[50001];
vector<pair<int, int>> vec;
int find(int a) {
	if (a == arr[a]) return 0;
	return arr[a];
}

void go_set(int n)
{
	ch[n] = true;
	for (int i = 0; i < v[n].size(); i++) {
		if (!ch[v[n][i]]) {
			ch[v[n][i]] = true;
			arr[v[n][i]] = n;
			height[v[n][i]] = height[n] + 1;
			go_set(v[n][i]);
		}
	}
}

int solve2(int a, int b) {
	while (1) {
		if (a == b) return a;
		a = find(a);
		b = find(b);
	}
}

int solve(int a, int b) {
	if (height[a] < height[b]) {
		while (1) {
			b = find(b);
			if (height[a] == height[b]) break;
		}
	}
	if (height[b] < height[a]) {
		while (1) {
			a = find(a);
			if (height[a] == height[b]) break;
		}
	}
	return solve2(a, b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n,m,a,b;
	cin >> n;
	height[1] = 1;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	go_set(1);
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		vec.push_back(make_pair(a, b));
	}
	for (int i = 0; i < vec.size(); i++) {
		cout<<solve(vec[i].first, vec[i].second)<<"\n";
	}
	return 0;
}