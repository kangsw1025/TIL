#include<iostream>
#include<map>
using namespace std;

long long n, p, q;

map<long long, long long> mp;

long long solve(long long idx) {
	if (mp[idx]) return mp[idx];

	mp[idx] = solve(idx / p) + solve(idx / q);
	return mp[idx];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> p >> q;

	mp[0] = 1;
	cout<< solve(n);

	return 0;
}