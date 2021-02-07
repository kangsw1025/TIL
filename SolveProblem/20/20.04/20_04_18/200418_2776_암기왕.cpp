#include <iostream>
#include<algorithm>
using namespace std;

int arr[1000001];
int pad[1000001];

void search(int n, int* arr, int s, int e)
{
	if (s == e) {
		if (n == arr[s]) cout << "1\n";
		else cout << "0\n";
		return;
	}
	int mid = (s + e) / 2;
	if (arr[mid] == n) {
		cout << "1\n";
		return;
	}
	else if (arr[mid] > n) search(n, arr, s, mid);
	else search(n, arr, mid + 1, e);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		for (int j = 0; j < num; j++) cin >> arr[j];
		sort(arr, arr + num);
		int num2;
		cin >> num2;
		for (int j = 0; j < num2; j++) cin >> pad[j];
		for (int j = 0; j < num2; j++) search(pad[j], arr, 0,num-1);
	}
	return 0;
}