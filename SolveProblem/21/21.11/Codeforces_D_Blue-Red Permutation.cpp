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
 
long long arr[200001];
 
bool cmp(int a, int b) {
	return a > b;
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
 
	int T;
	cin >> T;
	while (T--) {
		int n;
		vector<int> r, b;
		string s;
		cin >> n;
		for (int i = 0; i < n; i++) cin >> arr[i];
		cin >> s;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'R') r.push_back(arr[i]);
			else b.push_back(arr[i]);
		}
 
		sort(b.begin(), b.end());
		sort(r.begin(), r.end(), cmp);
	
		int left = 1, right = n;
		for (int i = 0; i < r.size(); i++) {
			if (r[i] <= right) right--;
		}
		for (int i = 0; i < b.size(); i++) {
			if (b[i] >= left) left++;
		}
 
		if (left > right) cout << "YES\n";
		else cout << "NO\n";
	}
 
	return 0;
}