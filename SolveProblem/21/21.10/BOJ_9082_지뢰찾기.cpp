#include <iostream>
#include <string>
using namespace std;

int n_y[3] = { -1,0,1 };

char arr[101];
char s[101];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int n, ans = 0;
		cin >> n;
		for (int i = 0; i < n; i++) cin >> arr[i];
		for (int i = 0; i < n; i++) {
			cin >> s[i];
			if (s[i] == '*') {
				ans++;
				for (int j = 0; j < 3; j++) {
					int ny = i + n_y[j];
					if (ny >= 0 && ny < n) arr[ny]--;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			if (s[i] == '#') {
				bool check = true;

				for (int j = 0; j < 3; j++) {
					int ny = i + n_y[j];
					if (ny >= 0 && ny < n) {
						if (arr[ny] == '0') check = false;
					}
				}

				if (check == false) continue;

				for (int j = 0; j < 3; j++) {
					int ny = i + n_y[j];
					if (ny >= 0 && ny < n)
						arr[ny]--;
				}
				ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}