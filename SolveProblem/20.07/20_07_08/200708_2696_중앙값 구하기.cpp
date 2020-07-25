#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	
	int n,m,num;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		int arr[10000];
		for (int j = 1; j <= m; j++)
			cin >> arr[j];
		if (m % 2 == 0) cout << m / 2 << "\n";
		else cout << m / 2 + 1 << "\n";
		priority_queue<int, vector<int>, greater<int>> max_q;
		priority_queue<int, vector<int>, less<int>> min_q;
		for (int j = 1; j <= m; j++) {			
			if (j % 2 == 1) {
				min_q.push(arr[j]);
				if (!max_q.empty() && max_q.top() < min_q.top()) {
					int a = max_q.top();
					max_q.pop();
					int b = min_q.top();
					min_q.pop();
					max_q.push(b);
					min_q.push(a);
				}
				cout << min_q.top()<<' ';
			}
			else {
				max_q.push(arr[j]);
			}
			if (j % 20 == 0 && j > 0) cout << "\n";
		}
		cout << "\n";
	}
	return 0;
}