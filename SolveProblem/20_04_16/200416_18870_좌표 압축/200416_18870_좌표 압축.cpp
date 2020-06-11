#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int arr[1000001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> vec;
	vector<int>::iterator itr;

	int n,sum;
	cin >> n;
	int si2 = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		vec.push_back(arr[i]);
		
	}
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());


	for (int i = 0; i < n; i++)
		cout<<lower_bound(vec.begin(), vec.end(), arr[i]) - vec.begin()<<' ';
	

	return 0;
}