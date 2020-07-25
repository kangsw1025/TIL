#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<pair<int, pair<int, int>>> vec;
int arr[10001];
int n, dt;

void reset(int a)
{
	for (int i = a; i <= dt; i++)
		if(arr[i]>arr[a]+(i-a)) arr[i] = arr[a] + (i - a);
}

int solve()
{
	for (int i = 0; i < vec.size(); i++) {
		int s = vec[i].first;
		int d = vec[i].second.first;
		int l = vec[i].second.second;
		if (arr[d] > arr[s] + l) arr[d] = arr[s] + l;
		reset(d);
		if (s > dt) break;
	}
	return arr[dt];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> dt;
	for (int i = 1; i <= dt; i++) arr[i] = i;
	int s, d, l;
	for (int i = 0; i < n; i++) {
		cin >> s >> d >> l;
		vec.push_back(make_pair(s, make_pair(d, l)));
	}
	sort(vec.begin(), vec.end());
	cout << solve();
	return 0;
}