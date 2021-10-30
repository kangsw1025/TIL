#include<iostream>
#include<string>
using namespace std;

int arr[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	string s;
	cin >> s;

	for (int i = 1, j = 0; i < n; i++) {
		while (j > 0 && s[i] != s[j]) j = arr[j - 1];
		if (s[i] == s[j]) arr[i] = ++j;
	}
	cout << n - arr[n - 1];
	return 0;
}