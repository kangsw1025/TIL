#include<iostream>
using namespace std;

const int MAX = 1e6 + 1;
int seg[MAX * 4];

void update(int idx, int val, int node, int start, int end) {
	if (idx<start || idx>end) return;

	seg[node] += val;

	if (start == end) return;

	int mid = (start + end) / 2;
	update(idx, val, node * 2, start, mid);
	update(idx, val, node * 2 + 1, mid + 1, end);
}

int query(int idx, int node, int start, int end) {
	if (start == end) return start;
	
	int mid = (start + end) / 2;

	if (idx <= seg[node * 2]) return query(idx, node * 2, start, mid);
	else return query(idx-seg[node*2], node * 2 + 1, mid + 1, end);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int a, b, c;
		cin >> a;
		if (a == 1) {
			cin >> b;
			int favor = query(b, 1, 1, MAX);
			cout << favor << "\n";
			update(favor, -1, 1, 1, MAX);
		}
		else {
			cin >> b >> c;
			update(b, c, 1,1, MAX);
		}
	}
	return 0;
}