#include <iostream>
#include <cmath>
using namespace std;

int N, cnt;
int arr[16];

bool ch(int i)
{
	int k = 1;
	bool check = true;

	while (k < i && check)
	{
		if (arr[i] == arr[k] || abs(arr[i] - arr[k]) == i - k)	check = false;
		k++;
	}
	return check;
}

void dfs(int i)
{
	if (ch(i))
	{
		if (i == N)	cnt++;
		else
			for (int j = 1; j <= N; j++)
			{
				arr[i + 1] = j;
				dfs(i + 1);
			}
	}
}

int main(void)

{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	dfs(0);

	cout << cnt << "\n";
	return 0;

}