#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,a,b;
	vector<pair<int, int>> vec;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		vec.push_back(make_pair(b, a));
	}
	sort(vec.begin(), vec.end());
	for (vector<pair<int, int>>::iterator itr = vec.begin(); itr != vec.end(); itr++)
		cout << itr->second << ' ' << itr->first << "\n";
}