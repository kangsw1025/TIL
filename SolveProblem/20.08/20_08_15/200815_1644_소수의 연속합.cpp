#include<iostream>
using namespace std;

int n;
bool arr[4000001];

void set() {
	for (int i = 2; i <=2000000; i++) 
		if (!arr[i]) 
			for (int j = 2; i * j <=4000000; j++) 
				arr[i * j] = true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	set();
	
	cin >> n;

	if (n == 1) cout << 0;
	else {
		int i = 2, j = 2;
		int sum = 2;
		int cnt = 0;
		while (i <= j && j <=n) {
			if (sum > n) {
				sum -= i;
				while (1) {
					i++;
					if (!arr[i]) break;
				}
			}
			else if (sum == n) {
				cnt++;
				sum -= i;
				while (1) {
					i++;
					if (!arr[i]) break;
				}
			}
			else{
				while (1) {
					j++;
					if (!arr[j]) break;
				}
				sum += j;
			}
		}
		cout << cnt;
	}
	return 0;
}