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
 
double arr[200001];
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
 
 
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
 
		double sum = 0;
		map<double, int> mp;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			sum += arr[i];
 
		}
 
		double k = sum / n * 2;
 
		long long cnt = 0;
 
		for (int i = 0; i < n; i++) {
			if (mp[k - arr[i]]) cnt += mp[k - arr[i]];
			mp[arr[i]]++;
		}
 
		cout << cnt<<"\n";
	}
 
	return 0;
}