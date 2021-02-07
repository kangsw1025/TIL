#include<iostream>
#include<queue>
using namespace std;

char word[500001];
int n, k;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	deque<char> q;

	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> word[i];
	
	for (int i = 0; i < n; i++) {
		while (k && !q.empty() && q.back() < word[i]) {
			q.pop_back();
			k--;
		}
		q.push_back(word[i]);
	}

	for (int i = 0; i < q.size() - k; i++) cout << q[i];
	
	return 0;
}