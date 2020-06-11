#include<iostream>
#include<cmath>
using namespace std;
//2 동쪽 6 서쪽
char arr[4][8];
bool ch[4];

void reset()
{
	for (int i = 0; i < 4; i++) ch[i] = false;
}
void turnright(int ar);
void turnleft(int ar);

void turnleft(int ar)
{
	ch[ar] = true;

	if (ar != 3) {
		if (ch[ar + 1] == false)
			if (arr[ar][2] != arr[ar + 1][6]) turnright(ar + 1);
	}
	if (ar != 0) {
		if (ch[ar - 1] == false)
			if (arr[ar][6] != arr[ar - 1][2]) turnright(ar - 1);
	}

	char w = arr[ar][0];
	for (int i = 0; i < 7; i++) arr[ar][i] = arr[ar][i + 1];
	arr[ar][7] = w;
	
}
void turnright(int ar)
{
	ch[ar] = true;

	if (ar != 3) {
		if (ch[ar + 1] == false)
			if (arr[ar][2] != arr[ar + 1][6]) turnleft(ar + 1);
	}
	if (ar != 0) {
		if (ch[ar - 1] == false)
			if (arr[ar][6] != arr[ar - 1][2]) turnleft(ar - 1);
	}

	char w = arr[ar][7];
	for (int i = 7; i >= 1; i--) arr[ar][i] = arr[ar][i - 1];
	arr[ar][0] = w;
	
}

int count()
{
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		if (arr[i][0] == '1') ans += pow(2, i);
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 8; j++) cin >> arr[i][j];

	int n, a, b;
	cin >> n;
	for (int i = 0; i < n; i++) {
		reset();
		cin >> a >> b;
		if (b == 1) turnright(a-1);
		else turnleft(a-1);
	}
	cout<<count();
	return 0;
}