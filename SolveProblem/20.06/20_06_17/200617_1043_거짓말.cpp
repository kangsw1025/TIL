#include<iostream>
#include<vector>
using namespace std;

int n, m;
bool lier[51];
vector<int> vec[51];

bool ch(int i)
{
	if (vec[i].size() == 0) return 1;
	if (lier[vec[i][0]] == false) return 1;
	return 0;
}

void solve(int k)
{
	bool check = true;

	for (int i = 0; i < vec[k].size(); i++) {
		if (lier[vec[k][i]] == true) {
			check = false;
			break;
		}
	}

	if (!check) {
		for (int i = 0; i < vec[k].size(); i++) lier[vec[k][i]] = true;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	int lie, num, l;
	cin >> lie;
	for (int i = 0; i < lie; i++) {
		cin >> num;
		lier[num] = true;
	}
	for (int i = 0; i < m; i++) {
		cin >> num;
		for (int j = 0; j < num; j++) {
			cin >> l;
			vec[i].push_back(l);
		}
	}
	int ans = 0;
	for (int j = 0; j < m; j++)
		for (int i = 0; i < m; i++)	solve(i);

	for (int i = 0; i < m; i++) ans += ch(i);
	cout << ans;
	return 0;
}