#include<iostream>
#include<string>
#include<map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map<string, string> mp;
	int a, b;
	string w1, w2;
	cin >> a >> b;
	string *word = new string[b];
	for (int i = 0; i < a; i++) {
		cin >> w1 >> w2;
		mp.insert(make_pair(w1, w2));
	}
	
	for (int i = 0; i < b; i++) {
		cin>>word[i];
		cout << mp[word[i]]<<"\n";
	}
	return 0;
}