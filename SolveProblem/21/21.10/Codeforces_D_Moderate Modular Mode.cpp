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
		long long x, y;
 
		cin >> x >> y;
 
		if (x > y) cout << x+y << "\n";
		else {
			if (y % x == 0) cout << x << "\n";
			else {
				int n = y/x *x;
				int dif = y - n;
				cout << n + (y-n)/ 2<<"\n";
			}
		}
	}
 
	return 0;
}