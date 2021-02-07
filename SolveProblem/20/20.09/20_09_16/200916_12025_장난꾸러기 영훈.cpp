#include<iostream>
#include<string>
#include<cmath>
using namespace std;

string word;
long long ans, cnt, n, Cnt = 1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> word >> cnt;
	n = cnt - 1;
	
	for (int i = 0; i < word.length(); i++)
		if (word[i] == '1' || word[i] == '2' || word[i] == '6' || word[i] == '7') {
			if (word[i] == '6' || word[i] == '7') word[i] -= 5;
			Cnt *= 2;
		}
	
	if (Cnt < cnt) cout << -1;
	else {
		for (int i = word.length() - 1; i >= 0; i--) {
			if (word[i] == '1' || word[i] == '2' || word[i] == '6' || word[i] == '7') {
				if (n % 2 == 1) {
					if (word[i] == '1' || word[i] == '2') word[i] += 5;
				}
				n /= 2;
			}
		}
		cout << word;
	}
	return 0;
}