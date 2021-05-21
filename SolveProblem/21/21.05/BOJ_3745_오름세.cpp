#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	while (cin>>n) {
		vector<int> vec;
		while(n--) {
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
		cout << vec.size() << "\n";
	}
	return 0;
}
