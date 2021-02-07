#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int* array = new int[n];
	for (int i = 0; i < n; i++) cin >> array[i];
	sort(array, array + n);
	for (int i = 0; i < n; i++) cout << array[i] << "\n";
	return 0;
}