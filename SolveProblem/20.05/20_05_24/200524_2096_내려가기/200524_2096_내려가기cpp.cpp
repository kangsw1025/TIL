#include<iostream>
#include<algorithm>
using namespace std;

int mp[3],mp2[3];
int sp[3],sp2[3];
int arr[100001][3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++) cin >> arr[i][j];
	
	for (int i = 0; i < 3; i++) {
		mp[i] = arr[0][i];
		sp[i] = arr[0][i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == 0) {
				mp2[0] = max(mp[0], mp[1]) + arr[i][0];
				sp2[0] = min(sp[0], sp[1]) + arr[i][0];
			}
			else if (j == 1) {
				mp2[1] = max(mp[2],max(mp[0], mp[1])) + arr[i][1];
				sp2[1] = min(sp[2],min(sp[0], sp[1])) + arr[i][1];
			}
			else {
				mp2[2] = max(mp[2], mp[1]) + arr[i][2];
				sp2[2] = min(sp[2], sp[1]) + arr[i][2];
			}
		}
		for (int j = 0; j < 3; j++) {
			mp[j] = mp2[j];
			sp[j] = sp2[j];
		}
	}

	cout << max(mp[0], max(mp[1], mp[2])) << ' ' << min(sp[0], min(sp[1], sp[2]));

	return 0;
}