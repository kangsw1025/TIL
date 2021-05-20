#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> vec;

	int T;
	cin >> T;
	for(int i = 0;i<T;i++) {
		int num;
		cin >> num;
		if (vec.empty()) vec.push_back(num);
		else {
			if (num > vec[vec.size() - 1]) vec.push_back(num);
			else {
				auto itr = lower_bound(vec.begin(), vec.end(), num);
				*itr = num;
			}
		}
	}
	cout << T - vec.size();
	return 0;
}