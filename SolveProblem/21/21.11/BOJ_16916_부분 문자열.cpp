#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> make_v(string b) {
	int len = b.length();
	vector<int> v(len);

	for (int i = 1, j = 0; i < len; i++) {
		while (j > 0 && b[i] != b[j]) {
			j = v[j - 1];
		}
		if (b[i] == b[j]) v[i] = ++j;
	}
	return v;
}

bool kmp(string a, string b) {
	vector<int> v = make_v(b);
	int alen = a.length();
	int blen = b.length();

	for (int i = 0, j = 0; i < alen; i++) {
		while (j > 0 && a[i] != b[j]) {
			j = v[j - 1];
		}
		if (a[i] == b[j]) {
			if (j == blen - 1) return true;
			else ++j;
		}
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string a, b;
	cin >> a >> b;

	cout << kmp(a, b);
	return 0;
}