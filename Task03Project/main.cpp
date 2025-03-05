#include <iostream>
using namespace std;

int main() {
	int n, m;
	int** matrix;

	cout << "Input size of the matrix (n and m): ";
	cin >> n >> m;

	matrix = new int* [n];

	for (int i = 0; i < n; i++)
	{
		// matrix[i] = new int[m];
		*(matrix + i) = new int[m];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			matrix[i][j] = rand() % 100;
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	int ilocal = -1;
	int jlocal = -1;

	for (int i = 1; i < n - 1; i++)
	{
		bool flag = false;

		for (int j = 1; j < m - 1; j++)
		{
			if (matrix[i][j] < matrix[i - 1][j] && matrix[i][j] < matrix[i + 1][j]
				&& matrix[i][j] < matrix[i][j - 1] && matrix[i][j] < matrix[i][j + 1]) {
				ilocal = i;
				jlocal = j;
				break;
				flag = true;
			}
		}

		if (flag) {
			break;
		}
	}

	if (matrix[0][0] < matrix[0][1] && matrix[0][0] < matrix[1][0]) {
		ilocal = 0;
		jlocal = 0;
	}
	else if (matrix[0][m - 1] < matrix[0][m - 2] && matrix[0][m - 1] < matrix[1][m - 1]) {
		ilocal = 0;
		jlocal = m - 1;
	}
	else if (matrix[n - 1][0] < matrix[n - 1][1] && matrix[n - 1][0] < matrix[n - 2][0]) {
		ilocal = n - 1;
		jlocal = 0;
	}
	else if (matrix[n - 1][m - 1] < matrix[n - 1][m - 2] && matrix[n - 1][m - 1] < matrix[n - 2][m - 1]) {
		ilocal = n - 1;
		jlocal = m - 1;
	}

	//...

	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}

	delete[] matrix;

	return 0;
}