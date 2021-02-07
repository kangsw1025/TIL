#include<iostream>
using namespace std;

bool check[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long so, ma;
	cin >> so >> ma;

	for (long long i = 2; i * i <= ma; i++) {
		long long s = so / (i * i);
		if (s * i * i != so) s++;
		for (long long j = s; i * i * j <= ma; j++)
			check[i * i * j - so] = true;
	}
	int cnt = 0;
	for (int i = 0; i < ma - so + 1; i++)
		if (!check[i]) cnt++;
	cout << cnt;
	return 0;
}