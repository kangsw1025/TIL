#include<iostream>
#include<deque>
using namespace std;

deque<pair<int, int>> dq;
int arr[5000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, l;
	cin >> n >> l;
	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = 0; i < n; i++) {
		if (!dq.empty() && dq.front().second < i - l+1) dq.pop_front();

		while (!dq.empty() && dq.back().first > arr[i]) dq.pop_back();

		dq.push_back(make_pair(arr[i], i));
		cout << dq.front().first << ' ';
	}
	return 0;
}