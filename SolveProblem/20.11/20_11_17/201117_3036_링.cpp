#include<iostream>
using namespace std;

int arr[101];

void solve(int idx) {
	int n1 = arr[0];
	int n2 = arr[idx];
	int id = 2;
	while (id <= n1 && id <= n2) {
		if (n1 % id == 0 && n2 % id == 0) {
			n1 /= id;
			n2 /= id;
		}
		else id++;
	}
	cout << n1 << '/' << n2 << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = 1; i < n; i++) solve(i);
	return 0;
}