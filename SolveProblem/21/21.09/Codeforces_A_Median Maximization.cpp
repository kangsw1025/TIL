#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
 
	int T;
	cin >> T;
	while (T--) {
		int a, b;
		cin >> a >> b;
 
		if (a % 2 == 0) {
			a -= (a / 2 - 1);
			cout << b / a << "\n";
		}
		else {
			a -= a / 2;
			cout << b / a << "\n";
		}
	}
	return 0;
}