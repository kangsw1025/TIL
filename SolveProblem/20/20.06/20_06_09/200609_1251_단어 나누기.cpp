#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	vector<string> v;
	string w;
	cin >> w;

	for (int i = 2; i < w.length(); i++) {
		for (int j = 1; j < i; j++) {
			string word;

			for (int f = j-1; f >= 0; f--) word += w[f];
			for (int f = i-1; f >= j; f--) word += w[f];
			for (int f = w.length()-1; f >=i; f--) word += w[f];

			v.push_back(word);
		}
	}
	sort(v.begin(), v.end());
	cout << v[0];
	return 0;
}