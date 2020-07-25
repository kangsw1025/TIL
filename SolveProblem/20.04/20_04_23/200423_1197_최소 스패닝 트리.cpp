#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool check[100001];
bool ar[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long sum = 0;
	vector<pair<int, pair<int, int>>> vec;

	int a, b, k = 0;
	int p, s, e;
	cin >> a >> b;

	for (int i = 0; i < b; i++) {
		cin >> s >> e >> p;
		vec.push_back(make_pair(p, make_pair(s, e)));
	}

	sort(vec.begin(), vec.end());


	sum += vec[0].first;
	check[vec[0].second.first] = true;
	check[vec[0].second.second] = true;
	k++;

	for (int i = 1; i < b; i++) {
		if (k == a - 1) break;
		if (ar[i] == false) {
			if (check[vec[i].second.first] == false && check[vec[i].second.second] == true) {
				check[vec[i].second.first] = true;
				sum += vec[i].first;
				k++;
				ar[i] = true;
				i = 0;
			}
			else if (check[vec[i].second.first] == true && check[vec[i].second.second] == false) {
				check[vec[i].second.second] = true;
				sum += vec[i].first;
				k++;
				ar[i] = true;
				i = 0;
			}
		}
	}
	cout << sum;
	return 0;
}