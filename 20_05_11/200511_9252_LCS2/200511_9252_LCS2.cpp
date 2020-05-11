#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int arr[1001][1001];
string wo[1001][1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string w1, w2;
	cin >> w1 >> w2;
	for (int i = 1; i <= w1.length(); i++) {
		for (int j = 1; j <= w2.length(); j++) {
			if (w1[i - 1] == w2[j - 1]) {
				arr[i][j] = arr[i - 1][j - 1] + 1;
				wo[i][j] = wo[i - 1][j - 1] + w1[i-1];
			}
			else {
				
				if (arr[i - 1][j] > arr[i][j - 1]) {
					wo[i][j] = wo[i - 1][j];
					arr[i][j] = arr[i - 1][j];
				}
				else {
					wo[i][j] = wo[i][j - 1];
					arr[i][j] = arr[i][j - 1];
				}
			}
		}
	}
	if (arr[w1.length()][w2.length()] == 0) cout << 0;
	else cout << arr[w1.length()][w2.length()] << "\n" << wo[w1.length()][w2.length()];
	return 0;
}