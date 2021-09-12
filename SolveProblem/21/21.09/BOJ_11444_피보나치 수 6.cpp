#include<iostream>
#include<vector>
using namespace std;

const int mod = 1e9 + 7;

vector<vector<long long>> mul(vector<vector<long long>>& a, vector<vector<long long>>& b) {
	vector<vector<long long>> tmp(2, vector<long long>(2));
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++)
				tmp[i][j] += a[i][k] * b[k][j];
			tmp[i][j] %= mod;
		}
	}
	return tmp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n;
	cin >> n;

	vector<vector<long long>> vec = { {0,1}, {1,0} };
	vector<vector<long long>> v = { {1,1}, {1,0} };

	while (n) {
		if (n % 2) vec = mul(v,vec);
		v = mul(v, v);
		n /= 2;
	}
	cout << vec[0][0];
	return 0;
}