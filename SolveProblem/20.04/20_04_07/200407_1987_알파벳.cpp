#include <iostream>
using namespace std;

char word[21][21];
bool ch[27];
int cnt, x, y;
int ma;


void dps(int a, int b, int c)
{
	ch[word[a][b] - 'A'] = true;
	cnt++;
	c++;
	if (c > ma) ma = c;
	if (a != 0 && ch[word[a - 1][b] - 'A'] == false) {
		dps(a - 1, b, c);
		ch[word[a - 1][b] - 'A'] = false;
	}
	if (a != x - 1 && ch[word[a + 1][b] - 'A'] == false) {
		dps(a + 1, b, c);
		ch[word[a + 1][b] - 'A'] = false;
	}
	if (b != 0 && ch[word[a][b - 1] - 'A'] == false) {
		dps(a, b - 1, c);
		ch[word[a][b - 1] - 'A'] = false;
	}
	if (b != y - 1 && ch[word[a][b + 1] - 'A'] == false) {
		dps(a, b + 1, c);
		ch[word[a][b + 1] - 'A'] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> x >> y;
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++) cin >> word[i][j];

	dps(0, 0, 0);
	cout << ma;
	return 0;
}