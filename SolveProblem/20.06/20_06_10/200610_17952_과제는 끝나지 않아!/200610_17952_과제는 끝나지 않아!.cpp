#include<iostream>
#include<stack>
using namespace std;

int arr[1000001];
int time[1000001];
stack<int> st;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, num, ans = 0, now;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> num;
		if (num == 1) {
			cin >> arr[i] >> time[i];
			st.push(i);
		}

		if (!st.empty()) {
			now = st.top();
			time[now]--;
			if (time[now] == 0) {
				ans += arr[now];
				st.pop();
			}
		}
	}
	cout << ans;
	return 0;
}