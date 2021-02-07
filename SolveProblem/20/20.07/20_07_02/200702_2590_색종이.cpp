#include<iostream>
#include<algorithm>
using namespace std;

int lef[7];

int solve() {
	int ans = 0;
	ans += lef[6];
	if (lef[5] > 0) {
		int fiv = lef[5];
		ans += fiv;
		lef[5] = 0;
		lef[1] = max(lef[1] - 11 * fiv,0);
	}
	if (lef[4] > 0) {
		while (lef[4] > 0) {
			ans++;
			lef[4]--;
			if (lef[2] > 0) {
				int two = min(lef[2],5);
				lef[2] = max(lef[2]-two,0);
				if (lef[1] > 0)
					lef[1] = max(lef[1] - (20 - two * 4), 0);
			}
			else if (lef[1] > 0) {
				lef[1] = max(lef[1] - 20, 0);
			}
		}
	}
	if (lef[3] > 0) {
		if (lef[3] >= 4) {
			while (lef[3] >= 4) {
				ans++;
				lef[3] -= 4;
			}
		}
		if (lef[3] == 3) {
			ans++;
			if (lef[2] > 0) {
				lef[2]--;
				if (lef[1] > 0) lef[1]  = max(lef[1]-5,0);
			}
			else if (lef[1] > 0) {
				lef[1] = max(lef[1] - 9, 0);
			}
		}
		else if (lef[3] == 2) {
			ans++;
			if (lef[2] > 0) {
				int two = min(lef[2], 3);
				lef[2] -= two;
				if (lef[1] > 0) {
					lef[1] = max(lef[1] - (18 - two * 4), 0);
				}
			}
			else if (lef[1] > 0) {
				lef[1] = max(lef[1] - 18, 0);
			}
		}
		else if (lef[3] == 1) {
			ans++;
			if (lef[2] > 0) {
				int two = min(lef[2], 5);
				lef[2] -= two;
				if (lef[1] > 0) {
					lef[1] = max(lef[1] - (27 - two * 4), 0);
				}
			}
			else if (lef[1] > 0) {
				lef[1] = max(lef[1] - 27, 0);
			}
		}
	}
	if (lef[2] > 0) {
		if (lef[2] >= 9) {
			while (lef[2] >= 9) {
				ans++;
				lef[2] -= 9;
			}
		}
		if (lef[2] > 0) {
			ans++;
			int two = lef[2];
			lef[2] = 0;
			lef[1] = max(lef[1] - (36 - two * 4), 0);
		}
	}
	if (lef[1] > 0) {
		while (lef[1] > 0) {
			ans++;
			lef[1] -= 36;
		}
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 1; i <= 6; i++) cin >> lef[i];

	cout<< solve();
	return 0;
}