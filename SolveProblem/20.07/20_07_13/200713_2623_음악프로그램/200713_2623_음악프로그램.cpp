#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class node {
public:
	int cnt = 0;
	vector<int> vec;
	node() {};
};

node nd[1001];
vector<int> ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, a, b, c;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a;
		for (int j = 0; j < a; j++) {
			if (j == 0) cin >> b;
			else {
				cin >> c;
				nd[b].vec.push_back(c);
				nd[c].cnt++;
				b = c;
			}
		}
	}

	queue<int> q;

	for (int i = 1; i <= n; i++)
		if (!nd[i].cnt) q.push(i);

	while (!q.empty()) {
		int x = q.front();
		q.pop();
	
		ans.push_back(x);

		for (int i = 0; i < nd[x].vec.size(); i++) {
			nd[nd[x].vec[i]].cnt--;
			if (nd[nd[x].vec[i]].cnt == 0) q.push(nd[x].vec[i]);
		}
	}
	if (ans.size() != n) cout << 0;
	else {
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << "\n";
		}
	}
	return 0;
}