#include<iostream>
#include<string>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, r =0;
	string word;
	cin >> n >> m;
	cin >> word;

	for (int i = 0; i < m; i++) {
		if (word[i + 1] == 'O' && word[i + 2] == 'I') {
			int cnt = 0;
			while (word[i] == 'I' && word[i + 1] == 'O')
			{
				i += 2;
				cnt++;
				if (word[i] == 'I' && cnt == n)
				{
					cnt--;
					r++;
				}
			}
		}
	}
	cout << r;
	return 0;
}