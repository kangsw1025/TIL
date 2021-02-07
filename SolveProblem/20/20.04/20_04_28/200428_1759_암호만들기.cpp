#include<iostream>
#include<algorithm>
using namespace std;

char word[16], ans[16];
int length;
int l, c;

bool check(int n)
{
	int w = 0, m = 0;
	for (int i = 0; i < n; i++) {
		if (ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'i' || ans[i] == 'o' || ans[i] == 'u')
			m++;
		else w++;
	}
	if (m >= 1 && w >= 2) return true;
	return false;
}

void make(int n, int m)
{
	if (n == l) {
		if (check(n)) {
			for (int i = 0; i < n; i++) cout << ans[i]; \
				cout << "\n";
		}
	}
	else {
		for (int i = m; i < c; i++) {
			ans[n] = word[i];
			make(n + 1, i + 1);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> l >> c;
	for (int i = 0; i < c; i++) cin >> word[i];
	sort(word, word + c);

	make(0,0);
	return 0;
}