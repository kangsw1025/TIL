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
 
int arr[100001];
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
 
	int T;
	cin >> T;
	while (T--) {
		int n;
		vector<int> v;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}
		bool can = true;
		for (int i = 1; i <= n; i++) {
			v.push_back(i + 1);
			bool div = false;
			for (int j = 0; j < v.size(); j++) {
				if (arr[i] % v[j]) {
					div = true;
					break;
				}
			}
			if (!div) {
				can = false;
				break;
			}
		}
 
		if (can) cout << "YES\n";
		else cout << "NO\n";
	}
 
 
	return 0;
}