#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;
 
const int INF = 2e9;
 
int win[51];
char arr[51];
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
 
	int T;
	cin >> T;
	while (T--) {
		vector<int> vec;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			if (arr[i] == '2') vec.push_back(i);
		}
 
		if (vec.size()>=1 && vec.size() <= 2) cout << "No\n";
		else {
			cout << "YES\n";
 
			if (vec.size()) {
				vec.push_back(vec[0]);
				for (int i = 0; i < vec.size() - 1; i++) {
					win[vec[i]] = vec[i + 1];
				}
			}
			
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (i == j) {
						cout << 'X';
						continue;
					}
					if (arr[i] == '1') cout << '=';
					else {
						if (arr[j] == '1') cout << '=';
						else {
							if (j == win[i]) cout << '+';
							else {
								if (win[j] == i) cout << '-';
								else cout << '=';
							}
						}
					}
				}
				cout << "\n";
			}
		}
	}
	return 0;
}