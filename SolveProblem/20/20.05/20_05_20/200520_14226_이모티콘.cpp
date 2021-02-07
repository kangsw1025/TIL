#include<iostream>
#include<queue>
using namespace std;

int n;
int arr[1001][1001];

int solve()
{
	queue<pair<int, int>> q;
	q.push(make_pair(0, 1));
	while (!q.empty()) {
		int num = q.front().second;
		int clip = q.front().first;
		if (num == n) return arr[clip][num];
		q.pop();
		if (clip == 0) {
			arr[num][num] = arr[clip][num] + 1;
			q.push(make_pair(num, num));
		}
		else {
			if (num + clip < 1001 && arr[clip][num + clip] == 0) {
				arr[clip][num + clip] = arr[clip][num] + 1;
				q.push(make_pair(clip, num + clip));
			}
			if (arr[clip][num - 1] == 0 && num > 3) {
				arr[clip][num - 1] = arr[clip][num] + 1;
				q.push(make_pair(clip, num - 1));
			}
			if (arr[num][num] == 0) {
				arr[num][num] = arr[clip][num] + 1;
				q.push(make_pair(num, num));
			}
		}

	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	cout << solve();
	return 0;
}