#include<iostream>
using namespace std;

bool check[21];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, num;
	string word;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> word;
		if (word == "add") {
			cin >> num;
			check[num] = true;
		}
		else if (word == "remove") {
			cin >> num;
			check[num] = false;
		}
		else if (word == "check") {
			cin >> num;
			if (check[num] == true) cout << "1\n";
			else cout << "0\n";
		}
		else if (word == "toggle") {
			cin >> num;
			if (check[num] == true) check[num] = false;
			else check[num] = true;
		}
		else if (word == "all") {
			for (int j = 1; j <= 20; j++) check[j] = true;
		}
		else if (word == "empty") {
			for (int j = 1; j <= 20; j++) check[j] = false;
		}
	}
	return 0;
}