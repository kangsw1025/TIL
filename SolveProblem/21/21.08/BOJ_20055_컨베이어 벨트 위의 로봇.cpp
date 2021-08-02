#include<iostream>
using namespace std;

int energy[201], container[101];
bool box[201];
int zero;

int changer(int idx, int n) {
	return (idx + 2 * n) % (2 * n);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < 2 * n; i++) cin >> energy[i];
	for (int i = 0; i < n; i++) container[i] = i;
	for (int i = 1; i; i++) {

		for (int j = 0; j < n; j++)
			container[j] = changer(container[j]-1,n);

		if (box[container[n-1]]) box[container[n-1]] = false;
		

		for (int j = n - 1; j >= 1; j--) {
			int idx = container[j];
			if (!box[idx] && energy[idx] && box[changer(idx - 1, n)]) {
				box[changer(idx - 1, n)] = false;
				box[idx] = true;
				energy[idx]--;
				if (energy[idx] == 0) zero++;
			}
		}

		if (box[container[n - 1]]) box[container[n - 1]] = false;

		int start = container[0];

		if (energy[start]) {
			box[start] = true;
			energy[start]--;
			if (energy[start] == 0) zero++;
		}

		if (zero >= k) {
			cout << i;
			break;
		}

	}
	return 0;
}