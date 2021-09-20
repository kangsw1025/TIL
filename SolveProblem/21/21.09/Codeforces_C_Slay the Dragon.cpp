#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
#include<string>
#include<map>
#include<stack>
using namespace std;
 
const long long INF = 2e18 + 1;
vector<long long> hero;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
 
	int n, m;
	long long sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long p;
		cin >> p;
		sum += p;
		hero.push_back(p);
	}
 
	sort(hero.begin(), hero.end());
 
	cin >> m;
	for (int i = 0; i < m; i++) {
		long long op, dp, attacker, diffence, zero = 0;
		cin >> dp >> op;
 
		auto itr = lower_bound(hero.begin(), hero.end(), dp);
		if (itr == hero.end()) {
			attacker = hero[n - 1];
			diffence = sum - attacker;
		}
		else {
			int idx = itr - hero.begin();
			if (idx == 0) {
				attacker = hero[0];
				diffence = sum - hero[0];
			}
			else {
				attacker = max(zero,dp - hero[idx]) + max(zero,op-(sum-hero[idx])) > max(zero,dp - hero[idx - 1]) + max(zero,op-(sum-hero[idx-1])) ? hero[idx - 1] : hero[idx];
				diffence = sum - attacker;
			}
		}
		cout << max(zero, dp - attacker) + max(zero, op - diffence) << "\n";
	}
 
	return 0;
}