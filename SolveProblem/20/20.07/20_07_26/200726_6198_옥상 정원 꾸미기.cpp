#include<iostream>
#include<stack>
using namespace std;

int arr[80001];
int look[80001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long ans = 0;
	stack<pair<int, int>> st;

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	
	for (int i = n; i >= 1; i--) {
		if (st.empty())
			st.push(make_pair(arr[i], i));
		else {
			if (arr[i] > st.top().first) {
				while (!st.empty() && arr[i] > st.top().first)
					st.pop();
				
				if (!st.empty()) {
					look[i] = st.top().second - i-1;
				}
				else if (st.empty()) {
					look[i] = n - i;
				}
			}

			st.push(make_pair(arr[i], i));
		}
	}
	for (int i = 1; i <= n; i++) ans += look[i];
	cout << ans;

	return 0;
}