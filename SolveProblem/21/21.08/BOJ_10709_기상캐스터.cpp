#include<iostream>
#include<cstring>
using namespace std;

int H, W;
int arr[101][101];
char clouds[101][101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> H >> W;
	memset(arr, -1, sizeof(arr));
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++) {
			cin >> clouds[i][j];
			if (clouds[i][j] == 'c') arr[i][j] = 0;
		}

	for (int i = 1; i < W; i++)
		for(int j =0;j<H;j++)
			if (arr[j][i] == -1 && arr[j][i - 1] != -1)
				arr[j][i] = arr[j][i - 1] + 1;


	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++)
			cout << arr[i][j] << ' ';
		cout << "\n";
	}

	return 0;
}