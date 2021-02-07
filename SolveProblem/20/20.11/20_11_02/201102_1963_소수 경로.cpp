#include<iostream>
#include<queue>
#include<string>
#include<cstring>
using namespace std;

bool sosu[10001];
bool check[10001];

void solve() {
	sosu[0] = true;
	sosu[1] = true;

	for (int i = 2; i <= 100; i++)
		if (!sosu[i])
			for (int j = 2; i * j <= 10000; j++) 
				sosu[i * j] = true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	
	int T;
	cin >> T;
	while (T--) {
		memset(check, false, sizeof(check));
		bool find = false;
		string a, b;
		cin >> a >> b;
		
		queue<pair<int, string>> q;
		q.push({ 0,a });
		check[stoi(a)] = true;
		while (!q.empty()) {
			int cnt = q.front().first;
			string now = q.front().second;
			q.pop();

			if (now == b) {
				cout << cnt<<"\n";
				find = true;
				break;
			}

			for (int i = 0; i < 4; i++) {
				for (int j = 0; j <= 9; j++) {
					if (i == 0 && j == 0) continue;
					string num = now;
					if (num[i] - '0' == j) continue;
					num[i] = j + '0';
					int number = stoi(num);
					if (!sosu[number]) {
						if (!check[number]) {
							check[number] = true;
							q.push({ cnt + 1,num });
						}
					}
				}
			}
		}
		if(!find)
			cout << "Impossible\n";
	}
	return 0;
}