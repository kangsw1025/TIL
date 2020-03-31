#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	int n=0;
	string w;
	cin >> w;
	for (int i = w.length()-1; i >=0; i--) {
		if (w[i] >= '0' && w[i] <= '9') n += (int)(w[i] - '0')*pow(16,w.length()-i-1);
		else if (w[i] >= 'A' && w[i] <= 'F') n += (int)(w[i] - 'A' + 10) * pow(16, w.length() - i - 1);
	}
	cout << n;
	return 0;
}