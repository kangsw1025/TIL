#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

vector<string> v;

bool cmp(string a, string b) {
	if (a.length() <= b.length()) {
		if (a.length() == b.length()) {
			int an = 0, bn = 0;
			for (int i = 0; i < a.length(); i++) {
				if (a[i] >= '0' && a[i] <= '9') an += (a[i] - '0');
				if (b[i] >= '0' && b[i] <= '9') bn += (b[i] - '0');
			}
			if (an <= bn) {
				if (an == bn) {
					string ar[2];
					ar[0] = a;
					ar[1] = b;
					sort(ar, ar + 2);
					if (ar[0] == a) return true;
					return false;
				}
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for(int i=0;i<n;i++) {
		string w;
		cin >> w;
		v.push_back(w);
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < n; i++) cout << v[i] << "\n";
	return 0;
}