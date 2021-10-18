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
 
bool p[20001];
int arr[101];
 
void init() {
	for (int i = 2; i <= 10000; i++) {
		if (!p[i])
			for (int j = 2; i * j <= 20000; j++) p[i * j] = true;
	}
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
 
	init();
 
	int T;
	cin >> T;
 
	while (T--) {
		int n, sum = 0;
		vector<int> v;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			if (arr[i] % 2) v.push_back(i);
			sum += arr[i];
		}
 
		if (p[sum]) {
			cout << n << "\n";
			for (int i = 1; i <= n; i++) cout << i << ' ';
			cout << "\n";
		}
		else {
			cout << n - 1 << "\n";
			for (int i = 1; i <= n; i++) {
				if (i == v[0]) continue;
				cout << i << ' ';
			}
			cout << "\n";
		}
	}
	return 0;
}