#include<iostream>
#include<string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string word, bomb;
	char ans[1000001];
	cin >> word >> bomb;

	int idx = 0;
	for (int i = 0; i < word.length(); i++) {
		ans[idx++] = word[i];
		if (ans[idx - 1] == bomb[bomb.length() - 1]) {
			if (idx - bomb.length() < 0) continue;

			bool check = true;
			for (int j = 0; j < bomb.length(); j++) {
				if (ans[idx - j - 1] != bomb[bomb.length() - j - 1]) {
					check = false;
					break;
				}
			}
			if (check) idx -= bomb.length();
		}
	}
	if (!idx) cout << "FRULA";
	else for (int i = 0; i < idx; i++) cout << ans[i];
	return 0;
}