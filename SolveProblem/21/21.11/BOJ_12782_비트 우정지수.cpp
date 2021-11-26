#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		string a, b;
		cin >> a >> b;
		int ao = 0, az = 0, bo = 0, bz = 0;
		for (int i = 0; i < a.length(); i++) {
			if (a[i] != b[i]) {
				if (a[i] == '1') ao++;
				else az++;

				if (b[i] == '1') bo++;
				else bz++;
			}
		}

		int swap = min(min(ao, az), min(bo, bz));
		ao -= swap;
		az -= swap;
		bo -= swap;
		bz -= swap;

		cout << swap + min(abs(ao-bo), abs(az-bz)) << "\n";
	}
	return 0;
}