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
#include<cstdlib>
using namespace std;
 
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
 
	int T;
	cin >> T;
	while (T--) {
		int u, v;
		cin >> u >> v;
 
		long long a = pow(u, 2), b = pow(v, 2);
		cout << (-1) * a << ' ' << b << "\n";
	}
 
	return 0;
}