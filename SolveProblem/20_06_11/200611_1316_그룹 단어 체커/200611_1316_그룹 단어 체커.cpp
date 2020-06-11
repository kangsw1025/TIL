#include<iostream>
#include<string>
using namespace std;

bool ap[27];

void reset()
{
	for (int i = 0; i < 26; i++) ap[i] = false;
}

int solve(string w)
{
	for (int i = 0; i < w.length(); i++) {
		
		if (ap[w[i]-'a'] == false) {
			if (w[i] != w[i + 1]) ap[w[i] - 'a'] = true;
		}
		else return 0;
	}
	return 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, ans = 0;;
	string wo;
	cin >> n;
	for (int i = 0; i < n; i++) {
		reset();
		cin >> wo;
		ans += solve(wo);
	}
	cout << ans;
	return 0;
}