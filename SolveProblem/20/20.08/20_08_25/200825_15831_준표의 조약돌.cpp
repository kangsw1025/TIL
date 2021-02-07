#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	string rock;
	int n, b, w;
	cin >> n >> b >> w;
	cin >> rock;

	int i = 0, j = 0, ans = 0;
	int black = 0, white = 0;
	if (rock[0] == 'W') white++;
	else if (rock[0] == 'B') black++;
	while (i <= j && j < n) {
		if (white >= w && black <= b) {
			ans = max(ans, j - i + 1);
		}

		if (black > b) {
			while (black > b) {
				if (rock[i] == 'W')
					white--;
				else black--;
				i++;
				if (i > j) {
					if (i < n) {
						j++;
						if (rock[j] == 'W') white++;
						else black++;
					}
					break;
				}
			}
		}
		else {
			j++;
			if (rock[j] == 'B') black++;
			else white++;
		}
	}
	cout << ans;
	return 0;
}