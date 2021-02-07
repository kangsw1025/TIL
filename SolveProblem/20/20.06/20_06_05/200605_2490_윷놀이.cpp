#include<iostream>
using namespace std;

int ans[3];

int main()
{
	int n;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> n;
			if (n == 0) ans[i]++;
		}
	}
	for (int i = 0; i < 3; i++) {
		if (ans[i] == 0) cout << "E\n";
		else if (ans[i] == 1) cout << "A\n";
		else if (ans[i] == 2) cout << "B\n";
		else if (ans[i] == 3) cout << "C\n";
		else cout << "D\n";
	}
	return 0;
}