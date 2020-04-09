#include<iostream>
#include<string>
using namespace std;

bool ch[51];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	string word;
	cin >> n;
	for (int i = 0; i < n; i++) {
		m = 0;
		cin >> word;
		for (int j = 0; j < word.length(); j++) {
			if (word[j] == '(') {
				ch[m++] = true;
			}
			else if (word[j] == ')') {
				m--;
				if (m < 0) {
					ch[0] = true;
					break;
				}
				ch[m] = false;
			}
		}
		if (ch[0] == false) cout << "YES\n";
		else {
			cout << "NO\n";
			for (int k = 0; k <= m; k++) ch[k] = false;
		}
	}
}