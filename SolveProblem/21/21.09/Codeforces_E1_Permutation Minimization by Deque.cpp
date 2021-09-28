#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<map>
#include<cmath>
#include<deque>
using namespace std;
 
int arr[200001];
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
 
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		deque<int> dq;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			if (dq.size() == 0) dq.push_back(num);
			else {
				if (dq[0] >= num) dq.push_front(num);
				else if (dq[0] < num) dq.push_back(num);
			}
		}
		for (int i = 0; i < n; i++) cout << dq[i] << ' ';
		cout << "\n";
	}
 
	return 0;
}