#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int a, b, c;
bool check[201][201][201];
vector<int> vec;

void solve() {
	queue<pair<int, pair<int, int>>> q;
	q.push(make_pair(0, make_pair(0, c)));

	while (!q.empty()) {
		int wa = q.front().first;
		int wb = q.front().second.first;
		int wc = q.front().second.second;
		q.pop();

		if (check[wa][wb][wc]) continue;

		check[wa][wb][wc] = true;

		if (wa == 0) vec.push_back(wc);

		if (wa + wb > b)
			q.push(make_pair(wa - b + wb, make_pair(b, wc)));
		else
			q.push(make_pair(0, make_pair(wa + wb, wc)));

		if (wa + wc > c)
			q.push(make_pair(wa - c + wc, make_pair(wb, c)));
		else
			q.push(make_pair(0, make_pair(wb, wa + wc)));

		if (wb + wa > a)
			q.push(make_pair(a, make_pair(wb - a + wa, wc)));
		else
			q.push(make_pair(wa + wb, make_pair(0, wc)));

		if (wb + wc > c)
			q.push(make_pair(wa, make_pair(wb - c + wc, c)));
		else
			q.push(make_pair(wa, make_pair(0, wb + wc)));

		if (wc + wa > a)
			q.push(make_pair(a, make_pair(wb, wc - a +wa)));
		else
			q.push(make_pair(wa + wc, make_pair(wb, 0)));

		if (wc + wb > b)
			q.push(make_pair(wa, make_pair(b, wc - b + wb)));
		else
			q.push(make_pair(wa , make_pair(wb + wc, 0)));
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> b >> c;
	solve();
	sort(vec.begin(), vec.end());

	for (int i = 0; i < vec.size(); i++) cout << vec[i] << ' ';
	return 0;
}