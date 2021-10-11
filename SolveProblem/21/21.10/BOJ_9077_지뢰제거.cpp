#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

int arr[10031][10031];

int func(int op, int x, int y, int dst) {
	int cnt = 0;
	if (op == 1) {
		for (int i = x - dst; i <= x + 10 - dst; i++)
			for (int j = y - dst; j <= y + 10 - dst; j++)
				if (arr[i][j]) cnt++;
	}
	else if (op == 2) {
		for (int i = x - 10 + dst; i <= x+dst; i++)
			for (int j = y-dst; j <= y + 10 - dst; j++)
				if (arr[i][j]) cnt++;
	}

	else if (op == 3) {
		for (int i = x-dst; i <= x + 10 - dst; i++)
			for (int j = y - 10 + dst; j <= y+dst; j++)
				if (arr[i][j]) cnt++;
	}

	else if (op == 4) {
		for (int i = x - 10 + dst; i <= x + dst; i++)
			for (int j = y - 10 + dst; j <= y + dst; j++)
				if (arr[i][j]) cnt++;
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		memset(arr, 0, sizeof(arr));

		vector<pair<int, int>> v;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			x += 10, y += 10;
			arr[x][y] = 1;
			v.push_back({ x,y });
		}
		
		int ans = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= 5; j++)
				ans = max(ans, func(1,v[i].first,v[i].second,j));
			
			for (int j = 0; j <= 5; j++)
				ans = max(ans, func(2, v[i].first, v[i].second, j));	

			for (int j = 0; j <= 5; j++)
				ans = max(ans, func(3, v[i].first, v[i].second, j));

			for (int j = 0; j <= 5; j++)
				ans = max(ans, func(4, v[i].first, v[i].second, j));
		}
		cout << ans << "\n";
	}
	return 0;
}