#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int n, m, k1, k2, tro1, tro2;
vector<int> t1[301], t2[301];
int troll[301];
bool check[301];

bool pick1(int num) {
	if (check[num]) return 0;
	check[num] = 1;

	for (int i = 0; i < t1[num].size(); i++) {
		int t = t1[num][i];
		if (!troll[t] || pick1(troll[t])) {
			troll[t] = num;
			return 1;
		}
	}
	return 0;
}

bool pick2(int num) {
	if (check[num]) return 0;
	check[num] = 1;

	for (int i = 0; i < t2[num].size(); i++) {
		int t = t2[num][i];
		if (!troll[t] || pick2(troll[t])) {
			troll[t] = num;
			return 1;
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k1 >> k2;
	for (int i = 0; i < k1; i++) {
		int a, b;
		cin >> a >> b;
		t1[a].push_back(b);
	}
	for (int i = 0; i < k2; i++) {
		int a, b;
		cin >> a >> b;
		t2[a].push_back(b);
	}

	for (int i = 1; i <= n; i++) {
		memset(check, 0, sizeof(check));
		if (pick1(i)) tro1++;
	}
	memset(troll, 0, sizeof(troll));
	for (int i = 1; i <= n; i++) {
		memset(check, 0, sizeof(check));
		if (pick2(i)) tro2++;
	}
	if (tro1 < tro2) cout << "네 다음 힐딱이";
	else cout << "그만 알아보자";
	return 0;
}