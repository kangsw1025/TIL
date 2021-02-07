#include<iostream>
#include<string>
using namespace std;

int main()
{
	string word;
	bool check;
	while (1) {
		check = true;
		cin >> word;
		if (word.length() == 1 && word[0] == '0') break;
		else {
			for (int i = 0; i < word.length() / 2; i++)
				if (word[i] != word[word.length() - i - 1]) check = false;
			if (check == true) cout << "yes\n";
			else cout << "no\n";
		}
	}
	return 0;
}