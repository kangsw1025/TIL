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
 
 
long long solve(long long x, long long n) {
	if (n == 0) return x;
 
	long long sum = 0;
 
	if (n <= 4) {
		if (n == 1) sum = -1;
		if (n == 2) sum = 1;
		if (n == 3) sum = 4;
	}
	else {
		if (n % 4 == 1) sum = (-1) * n;
		if (n % 4 == 2) sum = 1;
		if (n % 4 == 3) sum = n + 1;
	}
	
	if (x % 2) sum *= -1;
	return x + sum;
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
 
	int T;
	cin >> T;
	while (T--) {
		long long x, n;
		cin >> x >> n;
		cout<<solve(x, n)<<"\n";
	}
 
	return 0;
}