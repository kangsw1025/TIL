#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int arr[101];
bool check[101];
vector<int> vec[101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, a, b;;
	cin >> n >> a >> b;
	int T;
	cin >> T;
	while (T--) {
		int f1, f2;
		cin >> f1 >> f2;
		vec[f1].push_back(f2);
		vec[f2].push_back(f1);
	}
	fill(arr, arr + n, -1);
	arr[a] = 0;
	check[a] = true;
	queue<int> q;
	q.push(a);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (now == b) break;
		else {
			for (int i = 0; i < vec[now].size(); i++) {
				int nu = vec[now][i];
				if (!check[nu]) {
					check[nu] = true;
					arr[nu] = arr[now] + 1;
					q.push(nu);
				}
			}
		}
	}
	cout << arr[b];
	return 0;
}