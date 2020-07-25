#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> vec, vec1;
	vector<int>::iterator it;
	int n,num;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		vec.push_back(num);
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		vec1.push_back(num);
	}
	for (vector<int>::iterator itr = vec1.begin(); itr != vec1.end(); itr++) {
		it = find(vec.begin(), vec.end(), *itr);
		if (it != vec.end()) cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}