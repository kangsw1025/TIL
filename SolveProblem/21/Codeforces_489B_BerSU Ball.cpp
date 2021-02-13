#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int boys[101], girls[101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int boy, girl, ans = 0;
	cin >> boy;
	for (int i = 0; i < boy; i++) cin >> boys[i];
	cin >> girl;
	for (int i = 0; i < girl; i++) cin >> girls[i];
	sort(boys, boys + boy);
	sort(girls, girls + girl);

	int start = 0;
	for (int i = 0; i < boy; i++) {
		for (int j = start; j < girl; j++) {
			if (abs(boys[i] - girls[j]) <= 1) {
				start = j + 1;
				ans++;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}