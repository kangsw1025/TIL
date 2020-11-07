#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int tree, ant;
		cin >> tree >> ant;
		int Min = 0, Max = 0;
		for (int i = 0; i < ant; i++) {
			int num;
			cin >> num;
			Min = max(Min, min(num,tree - num));
			Max = max(Max, max(num,tree - num));
		}
		cout << Min << ' ' << Max<<"\n";
	}
	return 0;
}