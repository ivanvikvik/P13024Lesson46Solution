#include <iostream>
using namespace std;

int main() {
	int n, m;
	int* matrix;

	cout << "Input size of the matrix (n and m): ";
	cin >> n >> m;

	matrix = new int[n * m];

	int size = n * m;
	for (int i = 0; i < size; i++)
	{
		matrix[i] = rand() % 100;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << matrix[m * i + j] << " ";
		}
		cout << endl;
	}

	// logic

	int imax = 0;
	int jmax = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (*(matrix + m * i + j) > * (matrix + m * imax + jmax)) {
				imax = i;
				jmax = j;
			}
		}
	}

	cout << "Max element - matrix[" << imax + 1 << "][" << jmax + 1 << "]" << endl;

	delete[] matrix;

	return 0;
}