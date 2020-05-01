#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int v, e, sum, line;
vector<pair<int, pair<int, int>>> vec;
vector<pair<int, pair<int, int>>>::iterator itr;
int arr[1001];

int gp(int n)
{
	if (arr[n] == n) return n;
	else return gp(arr[n]);
}


void uon(int a, int b)
{
	int x = gp(a);
	int y = gp(b);
	if (x < y) arr[y] = x;
	else arr[x] = y;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> v >> e;
	for (int i = 1; i <= v; i++) arr[i] = i;
	int s, d, p;
	for (int i = 0; i < e; i++) {
		cin >> s >> d >> p;
		vec.push_back(make_pair(p, make_pair(s, d)));
	}
	sort(vec.begin(), vec.end());
	
	for (itr = vec.begin(); itr != vec.end(); itr++) {
		if (gp(itr->second.first) != gp(itr->second.second)) {
			uon(itr->second.first, itr->second.second);
			line++;
			sum += itr->first;
		}
		if (line == v - 1) {
			cout << sum;
			break;
		}
	}

	return 0;
}