#include<iostream>
#include<cstring>
using namespace std;

char w[1000001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int num = 0;
	cin >> w;
	
	if (strlen(w) == 1) {
		cout << 0 << "\n";
		if (w[0] % 3 == 0) cout << "YES";
		else cout << "NO";
	}

	else {
		int cnt = 1;
		for (int i = 0; i < strlen(w); i++)
			num += (int)(w[i] - '0');
		
		while (1) {
			if (num < 10) {
				cout << cnt << "\n";
				if (num % 3 == 0) cout << "YES";
				else cout << "NO";
				break;
			}
			else {
				int sum = 0;
				while (num) {
					sum += num % 10;
					num /= 10;
				}
				cnt++;
				num = sum;
			}
		}
	}
	return 0;
}