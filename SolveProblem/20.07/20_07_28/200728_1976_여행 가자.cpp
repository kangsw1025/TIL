#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int arr[301];

int find(int i) {
	if (arr[i] == i) return i;
	return find(arr[i]);
}

void unon(int a, int b) {
	if (a < b)	arr[b] = a;
	else arr[a] = b;
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) arr[i] = i;
	for(int i=1;i<=n;i++)
		for (int j = 1; j <= n; j++) {
			int num;
			cin >> num;

			if (num) {
				int ap = find(i);
				int bp = find(j);
				if (ap == bp) continue;
				else unon(ap, bp);
			}
		}
	int np;
	bool check = true;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		if (i == 0) np = find(num);
		else {
			if (find(num) != np) {
				check = false;
				break;
			}
		}
	}
	if (check) cout << "YES";
	else cout << "NO";
	return 0;
}