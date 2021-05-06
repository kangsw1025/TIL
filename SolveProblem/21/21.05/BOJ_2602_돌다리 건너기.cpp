#include<iostream>
#include<string>
using namespace std;

int angel_dp[101][21][5]; // 0 = R 1 = I 2 = N 3 = G 4 = S
int devil_dp[101][21][5];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string way, angel, devil;
	cin >> way >> angel >> devil;

	for (int i = 0; i < way.length(); i++) {
		int op;

		if (way[i] == 'R') op = 0;
		else if (way[i] == 'I') op = 1;
		else if (way[i] == 'N') op = 2;
		else if (way[i] == 'G') op = 3;
		else op = 4;

		if (i == 0) {
			for (int j = 0; j < angel.length(); j++) {
				if (angel[j] == way[0]) angel_dp[j][i][op] = 1;
				if (devil[j] == way[0]) devil_dp[j][i][op] = 1;
			}
		}
		else {
			int op2;

			if (way[i-1] == 'R') op2 = 0;
			else if (way[i-1] == 'I') op2 = 1;
			else if (way[i-1] == 'N') op2 = 2;
			else if (way[i-1] == 'G') op2 = 3;
			else op2 = 4;

			for (int j = i; j < angel.length(); j++) {

				if (angel[j] == way[i]) 
					for(int k = 0;k<j;k++) angel_dp[j][i][op] += devil_dp[k][i-1][op2];

				if (devil[j] == way[i]) 
					for(int k=0;k<j;k++) devil_dp[j][i][op] += angel_dp[k][i-1][op2];
			}
		}
	}

	int op;

	if (way[way.length()-1] == 'R') op = 0;
	else if (way[way.length() - 1] == 'I') op = 1;
	else if (way[way.length() - 1] == 'N') op = 2;
	else if (way[way.length() - 1] == 'G') op = 3;
	else op = 4;

	long long ans = 0;
	for (int i = way.length()-1; i < angel.length(); i++) {
		ans += angel_dp[i][way.length() - 1][op];
		ans += devil_dp[i][way.length() - 1][op];
	}

	cout << ans;
	return 0;
}