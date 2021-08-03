#include<iostream>
#include<algorithm>
using namespace std;

int w, h, T;
pair<int,int> arr[101];
pair<int, int> dong;

pair<int, int> changer(int f, int s) {
	pair<int, int> rst;
	if (f == 1) {
		rst.first = h;
		rst.second = s;
	}
	else if (f == 2) {
		rst.first = 0;
		rst.second = s;
	}
	else if (f == 3) {
		rst.first = h - s;
		rst.second = 0;
	}
	else {
		rst.first = h - s;
		rst.second = w;
	}
	return rst;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> w >> h;
	cin >> T;

	int f, s, ans = 0;

	for (int i = 0; i < T; i++) {
		cin >> f >> s;
		arr[i] = changer(f, s);
	}
	
	cin >> f >> s;
	dong = changer(f, s);

	for (int i = 0; i < T; i++) {
		if ((arr[i].first == 0 && dong.first == h) || (arr[i].first == h && dong.first == 0))
			ans += h + min(dong.second + arr[i].second, 2 * w - dong.second - arr[i].second);
		else if ((arr[i].second == 0 && dong.second == w) || (arr[i].second == w && dong.second == 0))
			ans += w + min(dong.first + arr[i].first, 2 * h - dong.first - arr[i].first);
		else ans += abs(dong.first - arr[i].first) + abs(dong.second - arr[i].second);
	}

	cout << ans;

	return 0;
}