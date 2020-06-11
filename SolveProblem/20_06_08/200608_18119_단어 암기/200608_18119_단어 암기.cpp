#include<iostream>
#include<vector>
#include<string>
#include<bitset>
using namespace std;

vector<bitset<26>> v;
vector<bitset<26>> cv;
int n, m;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	string wo;
	cin >> n >> m;

	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> wo;
		for (int j = 0; j < wo.length(); j++) {
			v[i][wo[j] - 'a'] = true;
		}
	}

	cv = v;

	int a, cnt;
	char b;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		cnt = 0;
		if (a == 1) {
			for (int j = 0; j < n; j++) {
				if (v[j][b - 'a'] == true)
					cv[j][b - 'a'] = false;
			}
		}
		else if (a == 2) {
			for (int j = 0; j < n; j++)
				if (v[j][b - 'a'] == true)
					cv[j][b - 'a'] = true;
		}

		for (int j = 0; j < n; j++)
			if (v[j] == cv[j]) cnt++;

		cout << cnt << "\n";
	}

		return 0;
	}
