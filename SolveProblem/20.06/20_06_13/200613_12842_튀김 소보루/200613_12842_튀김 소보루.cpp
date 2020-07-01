#include<iostream>
using namespace std;

int time[100001];
int eat[100001];

void eatbread(int n)
{
	for (int i = 1; i <= n; i++)
		if (eat[i] > 0) eat[i]--;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int have, left, lost;
	cin >> have >> left;
	lost = have - left;

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> time[i];

	if (lost <= n) cout << lost;
	else {
		int ea = 0;
		while (1) {
			for (int i = 1; i <= n; i++) {
				if (eat[i] == 0) {
					eat[i] = time[i];
					ea++;
				}
				if (ea == lost) {
					cout << i;
					return 0;
				}
			}
			eatbread(n);
		}
	}
}