#include<iostream>
#include<set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	set<int> s;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		s.insert(num);
	}

	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		auto itr = s.find(num);
		if (itr != s.end()) s.erase(itr);
	}
	cout << s.size() << "\n";
	for (auto itr : s) cout << itr << ' ';
	return 0;
}