#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

const int MAX = 5e5+1;

int n;
pair<int, int> connect[MAX];
pair<int, int> answer[MAX];
int cache[MAX];
bool visited[MAX];
stack<int> st;

int solve() {
	int idx = 0;
	int length = 0;
	cache[idx] = connect[0].second;
	answer[0] = { 0, connect[0].first };

	for (int i = 1; i < n; i++) {
		if (cache[idx] < connect[i].second) {
			cache[++idx] = connect[i].second;
			answer[i] = { idx, connect[i].first };
		}
		else {
			int idx2 = lower_bound(cache, cache + idx, connect[i].second) - cache;
			cache[idx2] = connect[i].second;
			answer[i] = { idx2, connect[i].first };
		}
	}
	return idx + 1;
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> connect[i].first >> connect[i].second;
		visited[connect[i].first] = true;
	}

	sort(connect, connect + n);

	int result = solve();

	cout << n - result << "\n";

	int num = result - 1;
	for (int i = n - 1; i >= 0; i--)
		if (answer[i].first == num) {
			st.push(answer[i].second);
			num--;
		}

	while (!st.empty()) {
		visited[st.top()] = false;
		st.pop();
	}

	for (int i = 0; i < MAX; i++)
		if (visited[i])	cout << i << "\n";
	return 0;
}