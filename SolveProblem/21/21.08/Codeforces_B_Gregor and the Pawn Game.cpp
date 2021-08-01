#include<iostream>
#include<cstring>
using namespace std;

char me[200001], op[200001];
bool use[200001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T,n;
	cin >> T;
	while (T--) {
		cin >> n;
		int ans = 0;
		memset(use, false, sizeof(use));
		for (int i = 0; i < n; i++) cin >> op[i];
		for (int i = 0; i < n; i++) {
			cin >> me[i];
			if (me[i] == '1') {
				if (op[i] == '1') {
					if (i != 0 ) {
						if (!use[i - 1] && op[i-1]=='1') {
							use[i - 1] = true;
							ans++;
							continue;
						}
					}
					if (i != n - 1) {
						if (!use[i + 1] && op[i+1]=='1') {
							use[i + 1] = true;
							ans++;
							continue;
						}
					}
				}
				if (op[i] == '0') {
					if (!use[i]) {
						use[i] = true;
						ans++;
						continue;
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}