#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

int n;
int arr[1000001];
vector<int> vec;
pair<int, int> p[1000001];
stack<int> s;

int solve() {
	int idx = 0;
	vec.push_back(arr[0]);
	p[0] = { 0,arr[0] };

	for (int i = 1; i < n; i++) {
		if (arr[i] > vec[idx]) {
			vec.push_back(arr[i]);
			idx++;
			p[i] = { idx,arr[i] };
		}
		else {
			int itr = lower_bound(vec.begin(), vec.end(), arr[i]) - vec.begin();
			vec[itr] = arr[i];
			p[i] = { itr,arr[i] };
		}
	}
	return idx + 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int num;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int cnt = solve();
	cout << cnt<<"\n";

	int c = cnt - 1;
	for (int i = n-1; i >= 0; i--) {
		if (p[i].first == c) {
			s.push(p[i].second);
			c--;
		}
	}
	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
	return 0;
}