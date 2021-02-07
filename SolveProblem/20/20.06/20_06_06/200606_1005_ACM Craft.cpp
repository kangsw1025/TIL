#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int arr[1001], ans[1001];
bool check[1001];

void reset(int n)
{
	for (int i = 1; i <= n; i++) {
		check[i] = false;
		ans[i] = 0;
	}
}

int go(int q, vector<int> *vec) {

	if (vec[q].empty()) {
		ans[q] = arr[q];
		check[q] = true;
		return arr[q];
	}

	int time = 0;
	for (int i = 0; i < vec[q].size(); i++) {
		int num = vec[q][i];
		if (check[num] == false) {
			time = max(go(num, vec), time);
		}
		else time = max(ans[num], time);
	}

	ans[q] = time + arr[q];
	check[q] = true;
	return time + arr[q];
}

int solve()
{
	int n, m, o, q;
	
	vector<int> vec[1001];

	cin >> n >> m;
	reset(n);
	for (int i = 1; i <= n; i++) {
		cin >> o;
		arr[i] = o;
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		vec[b].push_back(a);
	}
	cin >> q;

	return go(q, vec);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout<<solve()<<"\n";
	}
	return 0;
}
