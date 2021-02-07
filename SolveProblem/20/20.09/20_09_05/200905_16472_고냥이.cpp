#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int now = 1, ans;
int arr[26];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	string word;
	cin >> n >> word;
	int i = 0, j = 0;
	arr[word[0] - 'a']++;
	while (i <= j && j < word.length()) {
		if (now <= n) {
			ans = max(ans, j - i + 1);
			j++;
			if (arr[word[j] - 'a']++ == 0) now++;
		}
		else {
			if (arr[word[i] - 'a']-- == 1) now--;
			i++;
		}
	}
	cout << ans;
	return 0;
}