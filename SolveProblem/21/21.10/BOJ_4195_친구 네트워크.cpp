#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<cstring>
using namespace std;

map<int, int> ar, p;

int fi(int n) {
	if (p[n] == n) return n;
	return fi(p[n]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		map<string, int> mp;
		ar.clear();
		p.clear();
		int n;
		cin >> n;
		while (n--) {
			string a, b;
			cin >> a >> b;
			if (mp.find(a)==mp.end()) {
				mp[a] = mp.size() + 1;
				p[mp[a]] = mp[a];
				ar[mp[a]] = 1;
			}
			if (mp.find(b)==mp.end()) {
				mp[b] = mp.size() + 1;
				p[mp[b]] = mp[b];
				ar[mp[b]] = 1;
			}

			int a_idx = mp[a];
			int b_idx = mp[b];

			int ap = fi(a_idx);
			int bp = fi(b_idx);

			if (ap == bp) cout << ar[ap] << "\n";
			else {
				if (ap > bp) swap(ap, bp);
				ar[ap] += ar[bp];
				p[bp] = ap;
				cout << ar[ap] << "\n";
			}
		}
	}
	return 0;
}