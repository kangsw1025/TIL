#include <iostream>
#include <limits>

#define min(x,y) ((x)<(y)?(x):(y))

using namespace std;

int matrix_array[501][2];
long long min_array[501][501];

int MatrixChain(int matrix_num)
{
	for (int i = matrix_num; i > 0; --i)
	{
		for (int j = i + 1; j <= matrix_num; ++j)
		{
			min_array[i][j] = std::numeric_limits<int>::max();
			for (int k = i; k <= j; ++k)
			{
				min_array[i][j] = min(min_array[i][j], min_array[i][k] + min_array[k + 1][j] + (matrix_array[i][0] * matrix_array[k][1] * matrix_array[j][1]));
			}
		}
	}
	return min_array[1][matrix_num];
}

int main()
{
	int input_num, col, row;
	cin >> input_num;
	for (int i = 1; i <= input_num; i++)
	{
		cin >> col >> row;
		matrix_array[i][0] = col;
		matrix_array[i][1] = row;
	}

	cout << MatrixChain(input_num);
	return 0;
}