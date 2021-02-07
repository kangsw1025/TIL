#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

int parent[100001], number[100001];

int findparent(int n) {
	if (n == parent[n]) return n;
	return parent[n] = findparent(parent[n]);
}

void merge(int n1, int n2) {
	n1 = findparent(n1);
	n2 = findparent(n2);

	if (n1 != n2) {
		if (number[n1] < number[n2]) swap(n1, n2);

		parent[n2] = n1;
		number[n1] += number[n2];
		number[n2] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int cnt;
		cin >> cnt;

		map<string, int> mp;
		int idx = 1;
		for (int i = 0; i < 100001; i++) {
			number[i] = 1;
			parent[i] = i;
		}
		for (int j = 0; j < cnt; j++) {
			string w1, w2;
			cin >> w1 >> w2;
			if (mp.count(w1) == 0) mp[w1] = idx++;
			if (mp.count(w2) == 0) mp[w2] = idx++;

			int w1_p = findparent(mp[w1]);
			int w2_p = findparent(mp[w2]);

			if (w1_p == w2_p) cout << max(number[w1_p],number[w2_p]) << "\n";
			else {
				merge(w1_p, w2_p);
				cout << max(number[w1_p],number[w2_p]) << "\n";
			}
		}
	}
	return 0;
}