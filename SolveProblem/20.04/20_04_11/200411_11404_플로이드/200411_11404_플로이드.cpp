#include <iostream>
using namespace std;

int city;
int bus[101][101];



void start()
{
	for (int ad = 1; ad <= city; ad++) {
		for (int st = 1; st <= city; st++) {
			if (bus[st][ad] == 0) continue;
			for (int to = 1; to <= city; to++) {
				if (st == to || bus[ad][to] == 0) continue;
				if (bus[st][to] > bus[st][ad] + bus[ad][to] || bus[st][to] == 0)
					bus[st][to] = bus[st][ad] + bus[ad][to];
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, s, e, p;
	cin >> city;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s >> e >> p;
		if (bus[s][e] == 0) bus[s][e] = p;
		else if (bus[s][e] > p) bus[s][e] = p;
	}

	start();

	for (int i = 1; i <= city; i++) {
		for (int j = 1; j <= city; j++)
			cout << bus[i][j] << ' ';
		cout << "\n";
	}
	return 0;
}