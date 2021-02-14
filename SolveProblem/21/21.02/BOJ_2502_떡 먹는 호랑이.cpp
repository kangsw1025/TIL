#include <iostream>
using namespace std;

int ricecake[31];
int fib[31];

void prev() {
	fib[1] = 1;
	fib[2] = 1;
	for (int i = 3; i <= 30; i++) fib[i] = fib[i - 2] + fib[i - 1];
}

int main() {
	int day, count;
	int first, second, ans1, ans2;
	cin >> day >> count;
	prev();
	first = fib[day - 2];
	second = fib[day - 1];
	ans1 = 0;
	while (1) {
		ans1++;
		if ((count - first * ans1) % second) continue;
		ans2 = (count - first * ans1) / second;
		break;
	}
	cout << ans1 << "\n" << ans2;
	return 0;
}
