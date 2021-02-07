#include<iostream>
#include<string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	bool check = true;
	string word[50];
	cin >> n;
	for (int i = 0; i < n; i++) cin >> word[i];
	for (int i = 0; i < word[0].length(); i++) {
		check = true;
		for (int j = 0; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++)
				if (word[j][i] != word[k][i]) {
					check = false;
					break;
				}
			if (check == false) break;
		}
		if (check == false) cout << '?';
		else cout << word[0][i];
	}
	return 0;
}