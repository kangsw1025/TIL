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
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	vec.push_back(arr[0]);
	for (int i = 1; i < n; i++) {
		if (arr[i] > vec.back()) vec.push_back(arr[i]);
		else {
			itr = lower_bound(vec.begin(), vec.end(), arr[i]);
			*itr = arr[i];
		}
	}
	cout << vec.size();
	return 0;
}