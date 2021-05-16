#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;

bool out[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, ans = 0;
	vector<string> input;
	queue<string> output;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string num;
		cin >> num;
		input.push_back(num);
	}

	for (int i = 0; i < n; i++) {
		string num;
		cin >> num;
		output.push(num);
	}

	int idx = 0;
	while (!output.empty()) {
		if (out[idx]) idx++;
		else {
			string num = output.front();
			output.pop();
			if (num == input[idx]) {
				out[idx++] = true;
				continue;
			}
			else {
				auto itr = find(input.begin(), input.end(), num);
				out[itr - input.begin()] = true;
				ans++;
			}
		}
	}

	cout << ans;
	return 0;
}