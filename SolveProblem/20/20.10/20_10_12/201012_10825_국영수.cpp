#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

struct propil {
	string name;
	int kor;
	int eng;
	int math;
};

propil arr[100001];

bool cmp(propil a, propil b) {
	if (a.kor > b.kor) return true;
	else if (a.kor < b.kor) return false;
	if (a.eng < b.eng) return true;
	else if (a.eng > b.eng) return false;
	if (a.math > b.math) return true;
	else if (a.math < b.math) return false;
	return a.name < b.name;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string name;
		int kor, eng, math;
		cin >> name >> kor >> eng >> math;
		arr[i].name = name;
		arr[i].kor = kor;
		arr[i].eng = eng;
		arr[i].math = math;
	}

	sort(arr, arr + n, cmp);
	for (int i = 0; i < n; i++) cout << arr[i].name << "\n";
	return 0;
}