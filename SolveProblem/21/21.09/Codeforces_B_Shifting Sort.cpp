#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<map>
#include<cmath>
using namespace std;
 
int arr[51], arr2[51];
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
 
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector < pair<int, pair<int, int>>> v;
 
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			arr2[i] = arr[i];
		}
		sort(arr2, arr2 + n);
 
		for (int i = n - 1; i >= 0; i--) {
			for (int j = i; j >= 0; j--) {
				if (arr[j] == arr2[i]) {
					if (i == j) break;
					for (int k = j; k < i; k++) arr[k] = arr[k + 1];
					arr[i] = arr2[i];
					v.push_back({ 1,{j + 1,i + 1} });
				}
			}
		}
		cout << v.size() << "\n";
		if (v.size() == 0) cout << "\n";
		else for (int i = 0; i < v.size(); i++)
			cout << v[i].second.first << ' ' << v[i].second.second << ' ' << v[i].first << "\n";
	}
 
	return 0;
}
