#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int arr[101][101][101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string w1, w2, w3;
	cin >> w1 >> w2 >> w3;
	for (int i = 1; i <= w1.length(); i++) {
		for (int j = 1; j <= w2.length(); j++) {
			for (int k = 1; k <= w3.length(); k++) {
				if (w1[i - 1] == w2[j - 1] && w2[j - 1] == w3[k - 1]) {
					arr[i][j][k] = arr[i - 1][j - 1][k - 1] + 1;
				}
				else {
					arr[i][j][k] = max(arr[i - 1][j][k], max(arr[i][j - 1][k], arr[i][j][k - 1]));
				}
			}
		}
	}
	cout << arr[w1.length()][w2.length()][w3.length()];
	return 0;
}