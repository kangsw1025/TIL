#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int arr[100001];

int find(int n) {
	if (arr[n] == -1) return n;
	return arr[n] = find(arr[n]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int gate, airplane, ans = 0;
	cin >> gate >> airplane;

	bool can = true;

	memset(arr, -1, sizeof(arr));
	for (int i = 0; i < airplane; i++) {
		int n;
		cin >> n;
		int tmp = find(n);
		if (tmp == 0) break;
		ans++;
		arr[tmp] = tmp - 1;
	}


	cout << ans;
	return 0;
}