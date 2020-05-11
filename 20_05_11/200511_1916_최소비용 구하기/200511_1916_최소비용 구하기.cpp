#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<pair<int, int>> vec[1001];
priority_queue<int, vector<int>, greater<int>> q;
int arr[1001];

void start(int st)
{
	q.push(st);
	arr[st] = 0;
	while (!q.empty()) {
		int sp = q.top();
		q.pop();
		for (int i = 0; i < vec[sp].size(); i++) {
			if (arr[sp] + vec[sp][i].first < arr[vec[sp][i].second]) {
				arr[vec[sp][i].second] = arr[sp] + vec[sp][i].first;
				q.push(vec[sp][i].second);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, city, line = 0;
	int st, dt, pay;
	cin >> city >> n;
	fill_n(arr, 1001, 987654321);
	for (int i = 0; i < n; i++) {
		cin >> st >> dt >> pay;
		vec[st].push_back(make_pair(pay, dt));
	}
	cin >> st >> dt;
	start(st);
	cout << arr[dt];
	return 0;
}