#include <iostream>
using namespace std;

int main() {
	int n, m;
	int** matrix;

	cout << "Input size of the matrix (n and m): ";
	cin >> n >> m;

	matrix = new int*[n];

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

	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}

	delete[] matrix;

	return 0;
}