#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string w[1001];
string ans[1001];
string ch[1001];

void reset(int n)
{
	for (int i = 0; i < n; i++) {
		ans[i] = "";
		ch[i] = "";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	while (1) {
		cin >> n;
		if (n == 0) break;
		reset(n);

		for (int i = 0; i < n; i++) {
			cin >> w[i];
			for (int j = 0; j < w[i].length(); j++)
				ans[i] += tolower(w[i][j]);
		}
		sort(ans, ans + n);
		for (int i = 0; i < n; i++) {
			for(int j=0;j<w[i].length();j++)
				ch[i] += tolower(w[i][j]);
			if (ans[0] == ch[i]) {
				cout << w[i] << "\n";
				break;
			}
		}
	}
	return 0;
}