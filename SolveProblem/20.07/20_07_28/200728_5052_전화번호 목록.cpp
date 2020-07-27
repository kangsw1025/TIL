#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n,m;
	bool check;
	cin >> n;
	for (int i = 0; i < n; i++) {
		vector<string> vec;
		vector<string>::iterator itr;
		check = true;
		cin >> m;
		for (int j = 0; j < m; j++) {
			string word;
			cin >> word;
			vec.push_back(word);
		}
		sort(vec.begin(), vec.end());
		for (int j = 0; j < m-1; j++) {
			int now = vec[j].length();
			int comp = vec[j + 1].length();

			if (now > comp) continue;

			if (vec[j] == vec[j + 1].substr(0, now)) {
				check = false;
				break;
			}
		}
		if (check) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}