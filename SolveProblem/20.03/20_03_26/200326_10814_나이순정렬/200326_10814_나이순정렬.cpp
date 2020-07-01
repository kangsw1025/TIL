#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

bool com(pair<int,string> v1, pair<int,string> v2)
{
	if (v1.first < v2.first) return true;
	else return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	vector<pair<int, string>> vec;
	cin >> n;
	int age;
	string name;
	for (int i = 0; i < n; i++) {
		cin >> age >> name;
		vec.push_back(make_pair(age, name));
	}

	stable_sort(vec.begin(), vec.end(), com);
	for (vector < pair<int, string>>::iterator itr = vec.begin(); itr != vec.end();itr++)
		cout << itr->first <<' '<<itr->second<< "\n";
	return 0;
}