#include<iostream>
#include<string>
using namespace std;

int have[26];
string ans;

bool solve(string word) {
	for (int i = 0; i < word.length(); i++) have[word[i] - 'A']++;
	int odd = 0, odd_num;
	for (int i = 0; i < 26; i++) {
		if (have[i] % 2) {
			odd++;
			odd_num = i;
			if (odd == 2) return false;
		}
	}
	for (int i = 0; i < 26; i++) {
		int cnt = have[i]/2;
		for (int j = 0; j <cnt; j++) {
			ans += 'A' + i;
			have[i]--;
		}
	}

	if (odd) {
		ans += 'A' + odd_num;
		have[odd_num]--;
	}

	for (int i = 25; i >= 0; i--)
		for (int j = 0; j < have[i]; j++)
			ans += 'A' + i;
	
	return true;
}

int main() {
	string word;
	cin >> word;
	if (solve(word)) cout << ans;
	else cout << "I'm Sorry Hansoo";
	return 0;
}