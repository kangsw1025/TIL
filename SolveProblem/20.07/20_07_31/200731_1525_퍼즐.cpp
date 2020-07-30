#include<iostream>
#include<queue>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

int dst = 123456789;

map<int, int> mp;
int n_x[4] = { 0,1,0,-1 };
int n_y[4] = { 1,0,-1,0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int now = 0;
	for (int i = 0; i < 9; i++) {
		int n;
		cin >> n;
		if (n == 0) n = 9;
		now *= 10;
		now += n;
	}
	if (now == dst) cout << 0;
	else {
		queue<int> q;
		q.push(now);
		mp[now] = 0;
		while (!q.empty()) {
			int num = q.front();
			string word = to_string(num);
			q.pop();

			if (num == dst) break;

			int zero = word.find('9');

			int x = zero / 3;
			int y = zero % 3;

			for (int i = 0; i < 4; i++) {
				int nx = x + n_x[i];
				int ny = y + n_y[i];
				if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
					string nw = word;
					swap(nw[x * 3 + y], nw[nx * 3 + ny]);

					int number = stoi(nw);
					if (!mp[number]) {
						mp[number] = mp[num] + 1;
						q.push(number);
					}
				}
			}
		}
		if (!mp[dst]) cout << -1;
		else cout << mp[dst];
	}
	return 0;
}