#include <iostream>
using namespace std;

int word[1001][1001];
bool chk[1001];
int cnt, x, y;


void dps(int h)
{
	chk[h] = true;
	for (int i = 1; i <= x; i++)
		if (word[h][i] == true && chk[i] == false) dps(i);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b;
	cin >> x >> y;
	for (int i = 0; i < y; i++) {
		cin >> a >> b;
		word[a][b] = true;
		word[b][a] = true;
	}
	for (int i = 1; i <= x; i++) {
		if (chk[i] == false) {
			dps(i);
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}