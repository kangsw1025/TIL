#include<iostream>
using namespace std;

int N;

struct index {
	int arr[5][5] = { 0, };
};


index cnt(index p, index q) {
	index an;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				an.arr[i][j] = (an.arr[i][j] + p.arr[i][k] * q.arr[k][j])%1000;
			}
		}
	}

	return an;
}

index solve(index w, unsigned long long B) {
	if (B == 1) return w;
	else {
		index co = cnt(w,w);
		if (B % 2 == 0) {
			return solve(co, B / 2);
		}
		else {
			return cnt(solve(co, B / 2), w);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	index t1;

	int a, b, c, d;
	unsigned long long B;
	cin >> N >> B;
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) cin >> t1.arr[i][j];

	index ans = solve(t1, B);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cout << ans.arr[i][j]%1000 << ' ';
		cout << "\n";
	}

	return 0;
}