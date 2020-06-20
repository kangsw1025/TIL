#include<iostream>
using namespace std;

int n,one,zero,mi;
int arr[2188][2188];

bool ch(int sx, int sy, int size) {
	int c = arr[sx][sy];

	for(int i=sx;i<sx+size;i++)
		for(int j=sy;j<sy+size;j++) 
			if (arr[i][j] != c)
				return false;;

	return true;
}

void solve(int sx, int sy, int size) {
	if (size == 1) {
		if (arr[sx][sy] == -1) mi++;
		else if (arr[sx][sy] == 0) zero++;
		else if (arr[sx][sy] == 1) one++;
	}

	else {
		bool check;
		check = ch(sx, sy, size);
		if (check == true) {
			if (arr[sx][sy] == -1) mi++;
			else if (arr[sx][sy] == 0) zero++;
			else if (arr[sx][sy] == 1) one++;
		}
		else {
			int si = size / 3;
			solve(sx, sy, si);
			solve(sx, sy + si, si);
			solve(sx, sy + si * 2, si);
			solve(sx+si, sy, si);
			solve(sx+si, sy + si, si);
			solve(sx+si, sy + si * 2, si);
			solve(sx+si*2, sy, si);
			solve(sx+si*2, sy + si, si);
			solve(sx+si*2, sy + si * 2, si);
		}
	}

}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) cin >> arr[i][j];

	solve(0,0,n);
	cout << mi << "\n" << zero << "\n" << one;
	return 0;
}