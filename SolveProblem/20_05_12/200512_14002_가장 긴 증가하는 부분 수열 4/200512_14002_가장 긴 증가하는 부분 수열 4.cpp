#include<iostream>
#include<vector>
using namespace std;

int arr[1001];
int dp[1001];
vector<int> vec[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	
	for (int i = 0; i < n; i++) {
		int Min = 0;
		int num = 1001;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				if (Min < dp[j]) {
					Min = dp[j];
					num = j;
				}
			}
		}
		dp[i] = Min + 1;
		if (num != 1001)
			for (int k = 0; k < vec[num].size(); k++)
				vec[i].push_back(vec[num][k]);
		vec[i].push_back(arr[i]);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (dp[ans] < dp[i]) ans = i;
	}
	cout << dp[ans] << "\n";
	for (int i = 0; i < vec[ans].size(); i++)
		cout << vec[ans][i] << ' ';
	return 0;
}