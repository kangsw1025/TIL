#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	if (n == 2 || n == 6) cout << "Kali";
	else cout << "Ringo";
	return 0;
}