#include<iostream>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
struct compare {
	bool operator()(pair<long long, long long> a, pair<long long, long long> b)
	{
		if (a.first != b.first) return a.first > b.first;
		return a.second>b.second;
	}
};

priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, compare> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> m;
		if (m == 0) {
			if (q.empty()) cout << "0\n";
			else {
				cout << q.top().second<<"\n";
				q.pop();
			}
		}
		else q.push(make_pair(abs(m), m));
	}
	return 0;
}