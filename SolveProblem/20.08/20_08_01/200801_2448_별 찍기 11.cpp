#include<iostream>
using namespace std;

char tree[3073][6148];

char star[][6] =
{
	"  *  ",
	" * * ",
	"*****"
};

void solve(int n, int w, int h) {
	if (n == 1) {
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 5; j++) 
				tree[w+i][h+j] = star[i][j];
			
		
		return;
	}
	solve(n / 2, w, h + 3 * n / 2);
	solve(n / 2, w + 3 * n / 2, h);
	solve(n / 2, w + 3 * n / 2, h + 3 * n);
}

int main() {
	int n;
	cin >> n;
	solve(n / 3, 0, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n - 1; j++) {
			if (tree[i][j] == '*') cout << '*';
			else cout << ' ';
		}
		cout << "\n";
	}
	return 0;

}