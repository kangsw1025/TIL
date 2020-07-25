#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<string, string>> vec;
int arr[31];

void reset()
{
	for (int i = 0; i < 31; i++) arr[i] = 0;
	while (!vec.empty()) vec.pop_back();
}

int solve(int n)
{
	int ans = 1;
	for (int i = 0; i <= n; i++)
		ans = ans * (arr[i] + 1);
	return ans - 1;
}

int count()
{
	string word = "";
	int i = -1;
	for (int j = 0; j < vec.size(); j++) {
		if (word == vec[j].first) {
			arr[i]++;
		}
		else {
			i++;
			word = vec[j].first;
			arr[i]++;
		}
	}
	return i;
}

int main()
{
	int n, m;
	string w, o;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		reset();
		for (int j = 0; j < m; j++) {
			cin >> w >> o;
			vec.push_back(make_pair(o, w));
		}
		sort(vec.begin(), vec.end());
		int c = count();
		cout << solve(c) << "\n";
	}
	return 0;
}