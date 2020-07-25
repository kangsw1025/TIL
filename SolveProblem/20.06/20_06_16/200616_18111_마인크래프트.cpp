#include<iostream>
using namespace std;

int arr[501][501];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int x, y, b, t = 987564321, h;
	int max = 0, min = 256;
	cin >> x >> y >> b;

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cin >> arr[i][j];
			if (min > arr[i][j])
				min = arr[i][j];
			if (max < arr[i][j])
				max = arr[i][j];
		}
	}

	for (int i = min; i <= max; i++)
	{
		int time = 0;
		int block = b;
		for (int j = 0; j < x; j++)
		{
			for (int k = 0; k < y; k++)
			{
				int height = arr[j][k] - i;
				if (height > 0)
				{
					time = time + height * 2;
					block = block + height;
				}
				else if (height < 0)
				{
					time = time - height;
					block = block + height;
				}
			}
		}
		if (block >= 0)
		{
			if (time <= t)
			{
				t = time;
				h = i;
			}
		}
	}
	cout << t << ' ' << h;
	return 0;
}
