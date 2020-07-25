#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;
int arr[25];
bool ch[25];

priority_queue<pair<int, char>, vector<pair<int, char>>, less<pair<int, char>>> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n,m,po;
	char name;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> name >> po;
		if (po * 20 < n) continue;
		ch[name - 'A'] = true;
		for (int j = 1; j <= 14; j++) q.push(make_pair(po / j, name));
	}
	for (int i = 1; i <= 14; i++) {
		char w = q.top().second;
		arr[w - 'A']++;
		q.pop();
	}
	for (int i = 0; i < 25; i++)
		if (ch[i] == true) 
			cout << char(i + 'A') << ' ' << arr[i] << "\n";
	
	return 0;
}