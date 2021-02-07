#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

int arr[5][5];
set<int> vec;
int n_x[4] = { 0,1,0,-1 };
int n_y[4] = { 1,0,-1,0 };

void solve(int w, int h, int word, int idx) {
	if (idx == 5) {
		vec.insert(word);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = w + n_x[i];
		int ny = h + n_y[i];

		if(nx>=0 && nx<5 && ny>=0 && ny<5)
			solve(nx, ny, word*10+arr[nx][ny], idx + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++) cin >> arr[i][j];

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++) solve(i, j, arr[i][j], 0);

	cout << vec.size();
	return 0;
}