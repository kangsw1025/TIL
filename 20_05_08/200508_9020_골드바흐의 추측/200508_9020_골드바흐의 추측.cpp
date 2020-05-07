#include<iostream>
#include<vector>
using namespace std;

int arr[10001];

void cal(int num)
{
	bool check;
	for (int i = 3; i <= num; i++) {
		check = false;
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				check = true;
				break;
			}
		}
		if (check == false) arr[i] = i;
		else arr[i] = arr[i - 1];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	vector<int> vec;
	vector<int>::iterator itr;
	int n,num, Max = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		vec.push_back(num);
		if (num > Max) Max = num;
	}
	arr[2] = 2;
	cal(Max);
	for (itr = vec.begin(); itr != vec.end(); itr++) {
		for(int i = *itr / 2; i >= 2; i--) {
			if (arr[i] == i && *itr - i == arr[*itr - i]) {
				cout << i << ' ' << *itr - i << "\n";
				break;
			}
		}
	}

	return 0;
}