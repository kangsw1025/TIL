#include <iostream>
using namespace std;

bool al[101][101];
bool ch[101][101];
int n;

void dfs(int a, int b)
{
	for (int i = 0; i < n; i++) {
		if (al[b][i] == true && ch[a][i] == false) {
			ch[a][i] = true;
			dfs(a, i);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int num;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> num;
			if (num == 1) al[i][j] = true;
		}
	for (int i = 0; i < n; i++) {
		dfs(i,i);
		for (int j = 0; j < n; j++) {
			if (ch[i][j] == true) cout << "1 ";
			else cout << "0 ";
		}
		cout << "\n";
	}
	return 0;
}