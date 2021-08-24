#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int ar[1001], br[1001];
vector<int> a, b;
long long ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T, n, m;
	cin >> T >> n;
	for (int i = 0; i < n; i++)
		cin >> ar[i];
	
	cin >> m;
	for (int i = 0; i < m; i++)
		cin >> br[i];

	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = i; j < n; j++) {
			sum += ar[j];
			a.push_back(sum);
		}
	}

	for (int i = 0; i < m; i++) {
		int sum = 0;
		for (int j = i; j < m; j++) {
			sum += br[j];
			b.push_back(sum);
		}
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int l = 0, r = b.size() - 1;

	while (1) {
		if (a[l] + b[r] < T) l++;
		else if (a[l] + b[r] > T) r--;
		else if (a[l] + b[r] == T) {
			long long c1 = 1, c2 = 1;

			while (l + 1 < a.size() && a[l] == a[l + 1]) {
				l++;
				c1++;
			}

			while (r - 1 >= 0 && b[r] == b[r - 1]) {
				r--;
				c2++;
			}
			ans += c1 * c2;
			l++;
			r--;
		}

		if (l >= a.size() || r < 0) break;
	}
	cout << ans;
	return 0;
}