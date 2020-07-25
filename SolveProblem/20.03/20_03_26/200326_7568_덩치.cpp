#include <iostream>
using namespace std;

int r[50];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int* w = new int[n];
	int* h = new int[n];
	
	for (int i = 0; i < n; i++) cin >> w[i] >> h[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			else
				if (w[i] < w[j] && h[i] < h[j]) r[i]++;
		}
	}
	for (int i = 0; i < n; i++) cout << r[i]+1 << " ";
	return 0;
}