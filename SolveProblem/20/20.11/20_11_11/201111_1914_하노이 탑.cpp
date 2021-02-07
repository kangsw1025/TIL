#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int n;
long long cnt;
vector<pair<int, int>> v;

string bigNumAdd(string num1, string num2) {
	long long sum = 0;
	string rst;

	while (!num1.empty() || !num2.empty() || sum) {
		if (!num1.empty())
		{
			sum += num1.back() - '0';
			num1.pop_back();
		}
		if (!num2.empty())
		{
			sum += num2.back() - '0';
			num2.pop_back();
		}
		rst.push_back((sum % 10) + '0');

		sum /= 10;
	}
	reverse(rst.begin(), rst.end());
	return rst;
}

string solve(string num) {
	vector<int> v;
	int back = num.back() - '0';
	num.pop_back();
	back -= 1;
	num.push_back(back + '0');

	return num;
}

void Hanoi(int num, int from, int by, int to) {
	if (num == 1) v.push_back({ from, to });
	else {
		Hanoi(num - 1, from, to, by);
		v.push_back({ from,to });
		Hanoi(num - 1, by, from, to);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	if (n > 20) {
		string num = "2";
		for (int i = 0; i < n - 1; i++) {
			string temp = bigNumAdd(num, num);
			num = temp;
		}
		cout << solve(num);
	}
	else {
		Hanoi(n, 1, 2, 3);

		cout << v.size() << "\n";

		for (int i = 0; i < v.size(); i++)
			cout << v[i].first << " " << v[i].second << "\n";
	}
}