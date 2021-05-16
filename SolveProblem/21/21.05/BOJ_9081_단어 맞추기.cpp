#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		string word, copy;
		cin >> word;
		copy = word;
		if (next_permutation(word.begin(), word.end())) {
			cout << word << "\n";
		}
		else {
			cout << copy << "\n";
		}
	}
	return 0;
}