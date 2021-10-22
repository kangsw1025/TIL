#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	cout << (n % 4 == 3 ? 2 : 1);
	return 0;
}