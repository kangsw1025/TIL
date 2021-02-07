#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {

	int n, tmp;;
	vector <int> v;
	stack <int> s;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}

	vector <int> ans(v.size(), -1);

	for (int i = 0; i < v.size(); i++) {
		while (!s.empty() && v[s.top()] < v[i]) {
			ans[s.top()] = v[i];
			s.pop();
		}
		s.push(i);
	}

	for (int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
	return 0;
}