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
 
int solve(int a, int b, int c) {
	int mx = max(b, c);
 
	if (a > mx) return 0;
	return mx - a + 1;
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
 
 
	int T;
	cin >> T;
	
	while (T--) {
		int a, b, c;
		cin >> a >> b >> c;
 
		cout << solve(a, b, c)<<' '<<solve(b,a,c)<<' '<<solve(c,a,b)<<"\n";
	}
	return 0;
}