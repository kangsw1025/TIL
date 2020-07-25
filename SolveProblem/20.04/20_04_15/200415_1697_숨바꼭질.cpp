#include<iostream>
#include<queue>
using namespace std;

int n, k;
int arr[200002];

int acc(int num, int c)
{
	if (c == 1) return num + 1;
	else if (c == 2) return num - 1;
	else return num * 2;
}

void bfs(int f, int s)
{
	queue<int> q;
	q.push(f);

	while (!q.empty()) {
		int e = q.front();
		q.pop();

		for (int i = 1; i <= 3; i++) {
			int nf = acc(e, i);
			if (nf >= 0 && nf <= 200000 && arr[nf]==0) {
				q.push(nf);
				arr[nf] = arr[e] + 1;
				if (nf == s) return;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	if (n == k) cout << 0;
	else {
		bfs(n, k);
		cout << arr[k];
	}
	return 0;
}