#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, num, ans = 0;
	map<int, int> mp;
	cin >> a >> b;
	for (int i = 0; i < a+b; i++) {
		cin >> num;
		if (mp.find(num) == mp.end()) mp[num] = 1;
		else mp[num]++;
	}
	for (auto itr = mp.begin(); itr != mp.end(); itr++)
		if (itr->second == 1) ans++;
	cout << ans;
	return 0;
}