#include <iostream>
#include<algorithm>
#include <vector>
#include<cmath>
using namespace std;

bool ch(pair<int, int> a, pair<int, int> b) {
	if (a.first > b.first) return true;
	else return false;
}

int num[8002];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<pair<int, int>> vec;
	vector<pair<int, int>>::iterator itr, itr1;

	int n, mid, bin, ran, avr;
	int sum = 0, max = 0;

	cin >> n;
	if (n != 1) {
		int* arr = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			sum += arr[i];
			num[arr[i] + 4000]++;
		}

		sort(arr, arr + n);
		avr = sum / n;  // Æò±Õ

		if (sum >= 0) {
			if (sum % n * 2 >= n) avr++;
		}
		else {
			if (abs(sum) % n * 2 >= n) avr--;
		}

		mid = arr[n / 2];  // Áß¾Ó°ª

		for (int i = 0; i <= arr[n - 1] + 4000; i++)
			if (num[i] != 0)
				vec.push_back(make_pair(num[i], i - 4000));
		stable_sort(vec.begin(), vec.end(), ch);

		itr = vec.begin();
		itr1 = itr + 1;
		bin = itr->second;
		if (itr->first == itr1->first) bin = itr1->second; // ÃÖºó°ª
		ran = arr[n - 1] - arr[0]; // ¹üÀ§
		cout << avr << "\n" << mid << "\n" << bin << "\n" << ran;
	}
	else {
		cin >> avr;
		cout << avr << "\n" << avr << "\n" << avr << "\n" << 0;
	}
	return 0;
}