#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	if (x1 == x2) {
		int dif = abs(y2 - y1);
		cout << x1 + dif << ' ' << y1 << ' ' << x1 + dif << ' ' << y2;
	}
	else if (y1 == y2) {
		int dif = abs(x2 - x1);
		cout << x1<< ' ' << y1 + dif << ' ' << x2<< ' ' << y2 + dif;
	}
	else {
		if (abs(x1 - x2) != abs(y1 - y2)) cout << -1;
		else
			cout << x1 << ' ' << y2 << ' ' << x2 << ' ' << y1;
	}
	return 0;
}