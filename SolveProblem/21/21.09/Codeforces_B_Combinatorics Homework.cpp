#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
#include<string>
#include<map>
#include<stack>
using namespace std;
 
const int INF = 2e9 + 1;
 
int arr[3];
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
 
	int T;
	cin >> T;
	while (T--) {
		memset(arr, -1, sizeof(arr));
		int m;
		cin >> arr[0] >> arr[1] >> arr[2] >> m;
 
		sort(arr, arr + 3);
 
		int ap = max(0, arr[0] - 1), bp = max(0, arr[1] - 1), cp = max(0, arr[2] - 1);
		int dif = max(0, arr[2] - arr[1] - arr[0]);
 
		if (dif - 1 > m)	cout << "NO\n";
		else {
			if (m > ap + bp + cp) cout << "NO\n";
			else cout << "YES\n";
		}
	}
 
	return 0;
}