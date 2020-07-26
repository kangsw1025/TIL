#include<iostream>
#include<map>
#include<algorithm>
using namespace std;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	map<int, int> tree;

	int n,num;
	long long c = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (i == 0)	tree[num] = 1;
		else {
			auto itr = tree.upper_bound(num);
			int height = 0;

			if (itr != tree.end()) {
				height = itr->second;
			}

			if (itr != tree.begin()) {
				itr--;
				height = max(height, itr->second);
			}
			tree[num] = height + 1;
			c += height;
		}

		cout << c << "\n";
	}
	return 0;
}