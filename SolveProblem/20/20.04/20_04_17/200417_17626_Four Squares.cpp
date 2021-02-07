#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 500001;

using namespace std;

int main()
{
	int n;
	int minNum;
	int DP[50010] = { 0, };
	vector<int> v;

	cin >> n;

	DP[0] = 0;
	DP[1] = 1;

	for (int i = 1; i < 230; ++i)
		v.push_back(i * i);

	for (int i = 2; i <= n; ++i) {
		minNum = MAX;

		for (int j = 0; v[j] <= i; ++j) {
			int tmp = i - v[j];
			minNum = min(minNum, DP[tmp]);
		}

		DP[i] = minNum + 1;
	}

	cout << DP[n] << endl;

	return 0;
}