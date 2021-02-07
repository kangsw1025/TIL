#include<iostream>
#include<vector>
using namespace std;


void solve(int n)
{
	vector<int> vec,v;
	while (n) {
		vec.push_back(n % 2);
		n /= 2;
	}
	for (int i = vec.size()-2; i >=0; i--)
		v.push_back(vec[i]);

	for (int i = 0; i < v.size(); i++) {
		if (v[i] == 0) cout << 4;
		else cout << 7;
	}
}

int main()
{
	int n;
	cin >> n;
	solve(n+1);
	return 0;
}