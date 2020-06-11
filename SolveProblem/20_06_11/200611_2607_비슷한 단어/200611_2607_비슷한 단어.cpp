#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

char first[10];
char word[10];

void reset()
{
	for (int i = 0; i < 10; i++) word[i] = NULL;
}

int solve(char* wo)
{
	if (abs((int)(strlen(wo) - strlen(first))) > 1) return 0;

	int k = 0, cnt = 0;
	for (int i = 0; i < strlen(first); i++) {
		for (int j = k; j < strlen(wo); j++) {
			if (first[i] == wo[j]) {
				cnt++;
				i++;
				k = j+1;
			}
		}
	}
	if (strlen(wo) > strlen(first)) if (cnt == strlen(first)) return 1;
	if (strlen(wo) < strlen(first)) if (cnt == strlen(wo)) return 1;
	if (strlen(wo) == strlen(first)) if (strlen(first) - cnt <= 1) return 1;
	return 0;
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, ans = 0;
	cin >> n;
	cin >> first;
	sort(first, first + strlen(first));
	for (int i = 1; i < n; i++) {
		reset();
		cin >> word;
		sort(word, word + strlen(word));
		ans += solve(word);
	}
	cout << ans;
	return 0;
}