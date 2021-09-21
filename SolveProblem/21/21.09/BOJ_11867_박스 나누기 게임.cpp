#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b;
	cin >> a >> b;
	if (a%2==0 || b%2==0) cout << "A";
	else cout << "B";
	
	return 0;
}