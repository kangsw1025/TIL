#include <iostream>
using namespace std;

bool check[5001];
int arr[5001];

void foo(int a, int b) {
	int num = 0, n = 0;
	for (int i = 1; i <= a; i++) arr[i] = i;
	cout << '<';
	for (int i = 0; i >= 0; i++) {
		if (check[i % a + 1] == false) {
			n++;
			if (n == b) {
				check[i % a + 1] = true;
				num++;
				n = 0;
				if (num == a) {
					cout << (i % a) + 1 << '>';
					return;
				}
				else cout << (i % a) + 1 << ", ";
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	foo(n, m);

	return 0;
}