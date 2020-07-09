/*
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int ans = 987654321;

int solve(int n) {
	int cnt = 1;
	int Max = 0;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			Max = max(Max, max(solve(i), solve(n / i)));
		}
	}
	return cnt+Max;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			ans = min(ans, max(solve(i), solve(n / i)));
		}
	}
	if (ans == 987654321) cout << 0;
	else cout << ans;
	return 0;
}*/

#include<iostream>
#include<cmath>
using namespace std;

int solve(int n)
{
	int cnt = 0;
	int tmp = n;

	for (int i = 2; i < n; i++)
		if (n % i == 0)
			while (tmp % i == 0) {
				cnt++;
				tmp /= i;
			}

	if (cnt == 0)
		return 1;

	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin>>n;

	cout << ceil(log2(solve(n)));

	return 0;
}

