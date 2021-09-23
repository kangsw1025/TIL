#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int arr[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, num;
	vector<int> vec;

	cin >> n;
	while (n--) {
		cin >> num;
		arr[num]++;
		vec.push_back(num);
	}

	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	for (int i = 0; i < vec.size(); i++) {
		int val = vec[i];

		if (arr[val] % 2 == 1) {
			cout << "koosaga";
			return 0;
		}
	}
	cout << "cubelover";
	return 0;
}