#include <iostream>
#include <deque>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	deque<int> de;
	deque<int>::iterator itr;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) de.push_back(i);
	while (de.size()!=1) {
		de.pop_front();
		itr = de.begin();
		de.push_back(*itr);
		de.pop_front();
	}
	itr = de.begin();
	cout << *itr;
	return 0;
}