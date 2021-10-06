#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;

int arr[1000001], cnt[1000001], rst[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		cnt[arr[i]]++;
	}

	stack<pair<int, int>> st;

	for (int i = n; i >= 1; i--) {
		while (!st.empty() && cnt[arr[i]] >= st.top().first) {
			st.pop();
		}

		rst[i] = st.empty() ? -1 : st.top().second;

		st.push({ cnt[arr[i]],arr[i] });
	}

	for (int i = 1; i <= n; i++) cout << rst[i] << ' ';
	
	return 0;
}