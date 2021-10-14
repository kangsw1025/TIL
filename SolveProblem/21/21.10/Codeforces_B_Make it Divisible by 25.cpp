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
 
int solve(string n) {
	int i, j;
	for (i = n.length() - 1; i >= 0; i--) if (n[i] == '0') break;
	for (j = i - 1; j >= 0; j--) 
		if (n[j] == '0' || n[j] == '5') break;
	int rst =  (n.length() - 1 - i)  + (i - j - 1);
 
	for (i = n.length() - 1; i >= 0; i--) if (n[i] == '5') break;
	for (j = i - 1; j >= 0; j--) 
		if (n[j] == '2' || n[j] == '7') break;
		
	rst = min(rst, int((n.length() - 1 - i) + (i - j - 1)));
	return rst;
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
 
 
	int T;
	cin >> T;
	
	while (T--) {
		string n;
		cin >> n;
		cout<<solve(n)<<"\n";
	}
	return 0;
}