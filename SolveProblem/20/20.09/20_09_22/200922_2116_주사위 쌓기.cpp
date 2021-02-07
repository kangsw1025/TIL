#include<iostream>
#include<algorithm>
using namespace std;

int T, ans;
int dice[6], dice_sum[7], start[7];
bool first;

int opposit(int n) {
	if (n == 0) return 5;
	if (n == 1) return 3;
	if (n == 2) return 4;
	if (n == 3) return 1;
	if (n == 4) return 2;
	if (n == 5) return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	while (T--) {
		for (int i = 0; i < 6; i++) cin >> dice[i];
		if (!first) {
			for (int i = 1; i <= 6; i++) {
				if (dice[0] == i || dice[5] == i) {
					int high = max(dice[1], dice[2]);
					high = max(high, max(dice[3], dice[4]));
					dice_sum[i] += high;
				}
				else if (dice[1] == i || dice[3] == i) {
					int high = max(dice[0], dice[2]);
					high = max(high, max(dice[4], dice[5]));
					dice_sum[i] += high;
				}
				else if (dice[2] == i || dice[4] == i) {
					int high = max(dice[0], dice[1]);
					high = max(high, max(dice[3], dice[5]));
					dice_sum[i] += high;
				}
				start[i] = i;
				ans = max(ans, dice_sum[i]);
			}
			first = true;
		}
		else {
			for (int i = 1; i <= 6; i++) {
				if (dice[0] == start[i] || dice[5] == start[i]) {
					if (dice[0] == start[i]) start[i] = dice[5];
					else start[i] = dice[0];

					int high = max(dice[1], dice[2]);
					high = max(high, max(dice[3], dice[4]));
					dice_sum[i] += high;
				}
				else if (dice[1] == start[i] || dice[3] == start[i]) {
					if (dice[1] == start[i]) start[i] = dice[3];
					else start[i] = dice[1];

					int high = max(dice[0], dice[2]);
					high = max(high, max(dice[4], dice[5]));
					dice_sum[i] += high;
				}
				else if (dice[2] == start[i] || dice[4] == start[i]) {
					if (dice[2] == start[i]) start[i] = dice[4];
					else start[i] = dice[2];

					int high = max(dice[0], dice[1]);
					high = max(high, max(dice[3], dice[5]));
					dice_sum[i] += high;
				}
				ans = max(ans, dice_sum[i]);
			}
		}
	}
	cout << ans;
	return 0;
}