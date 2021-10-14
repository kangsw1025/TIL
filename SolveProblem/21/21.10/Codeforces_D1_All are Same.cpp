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
 
int gcd(int a, int b) {
	if (b > a) swap(a, b);
 
	if (b == 0) return a;
	return gcd(b, a % b);
}
 
int solve(vector<int> v) {
	queue<int> q;
 
	for (int i = 0; i < v.size(); i++)
		q.push(v[i]);
 
	while (q.size() != 1) {
		int first = q.front();
		q.pop();
		int second = q.front();
		q.pop();
 
		int gcd_val = gcd(first, second);
 
		q.push(gcd_val);
	}
	
	return q.front();
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
 
 
	int T;
	cin >> T;
 
	while (T--) {
		vector<int> v, gap;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int val;
			cin >> val;
			v.push_back(val);
		}
 
		sort(v.begin(), v.end());
 
		v.erase(unique(v.begin(), v.end()), v.end());
 
		if (v.size() == 1) {
			cout << "-1\n";
			continue;
		}
 
		for (int i = 0; i < v.size() - 1; i++) {
			int dif = v[i + 1] - v[i];
			gap.push_back(dif);
		}
 
		sort(gap.begin(), gap.end());
		gap.erase(unique(gap.begin(), gap.end()), gap.end());
 
		cout << solve(gap) << "\n";
	}
	return 0;
}