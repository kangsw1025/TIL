#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int n, m;
int arr[10];
string dp[51];

string cmp(string f, string s) {
	if (f.length() == s.length()) {
		if( s < f) return f;
		return s;
	}
	if(f.length()<s.length()) return s;
	return f;
}

string make_str(string f, string s) {
	string ret;

	for (int i = 0; i < f.length(); i++) {
		string tmp = f;
		tmp.insert(i, s);
		ret = cmp(ret, tmp);
	}

	int idx = 0;

	if (ret != "0" && ret[0] == '0') {
		while (idx < ret.length() && ret[idx] == '0') idx++;
		ret = ret.substr(idx, ret.length() - idx);
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	cin >> m;

	for(int i=0;i<n;i++)
		for (int j = arr[i]; j <= 50; j++)
			dp[j] = cmp(dp[j], to_string(i));
		
	for (int i = 1; i <= 50; i++)
		for (int j = 0; j < n; j++) {
			string str = to_string(j);
			if (i - arr[j] >= 0)
				dp[i] = cmp(dp[i], make_str(dp[i - arr[j]], str));
		}
	
	cout << dp[m];

	return 0;
}
