#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;

struct tree {
	map<string, tree*> m;

	void insert(vector<string>& v, int idx) {
		if (v.size() == idx) return;

		if (m.find(v[idx]) == m.end()) {
			m.insert({ v[idx], new tree() });
			m[v[idx]]->insert(v, idx + 1);
		}

		else m[v[idx]]->insert(v, idx + 1);
	}

	void find(int depth) {
		for (auto itr = m.begin(); itr != m.end(); itr++) {

			for (int i = 0; i < depth; i++)
				cout << "--";
			cout << itr->first << "\n";

			itr->second->find(depth + 1);
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	tree* root = new tree();

	for (int i = 0; i < n; i++) {
		int k; cin >> k;

		vector<string> v(k);

		for (int j = 0; j < k; j++) cin >> v[j];

		root->insert(v, 0);
	}
	root->find(0);
	return 0;
}