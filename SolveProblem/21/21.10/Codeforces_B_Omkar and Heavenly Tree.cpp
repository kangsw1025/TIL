#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<map>
#include<cmath>
#include<deque>
#include<set>
#include<vector>
using namespace std;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
 
 
	int T;
	cin >> T;
 
	while (T--) {
 
		set<int> s;
 
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++) s.insert(i);
 
		for (int i = 0; i < m; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			s.erase(b);
		}
		
		auto itr = s.begin();
		int root = *itr;
		for (int i = 1; i <= n; i++) {
			if (i == root) continue;
			cout << root << ' ' << i << "\n";
		}
	}
	return 0;
}