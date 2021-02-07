#include<iostream>
#include<string>
using namespace std;

int arr[27];
int Len, ans;

void solve(int idx, int now) {
	if (idx == Len) ans++;
	else {
		for (int i = 0; i < 26; i++) {
			if (i == now) continue;
			if (arr[i]) {
				arr[i]--;
				solve(idx + 1, i);
				arr[i]++;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string word;
	cin >> word;
	Len = word.length();
	for (int i = 0; i < Len; i++)
		arr[word[i] - 'a']++;

	for(int i=0;i<26;i++)
		if (arr[i]) {
			arr[i]--;
			solve(1, i);
			arr[i]++;
		}
	cout << ans;
	return 0;
}