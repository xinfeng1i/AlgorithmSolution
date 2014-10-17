#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

/**
 * Return the determinant of square matrix using Guass Elimination
 * Time Complexity: O(n^3)
 * If the matrix is singular, return 0
 * --------
 * Ref: Wikipedia: Guassian elimination
 */
int MatrixDeterminant(const vector<vector<int> >& adjMatrix)
{
	int n = adjMatrix.size();
	// copy to A
	vector<vector<double> > A(n, vector<double>(n, 0));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			A[i][j] = adjMatrix[i][j];
		}
	}

	bool IsSingular = false;
	double coeff = 1;
	
	// pivot pos A[k][k], for each pivot
	for (int k = 0; k < n; ++k)
	{
		// find pivot row
		double maxPivot = abs(A[k][k]);
		int maxIndex = k;
		for (int i = k + 1; i < n; ++i)
		{
			if (abs(A[i][k]) > maxPivot)
			{
				maxPivot = abs(A[i][k]);
				maxIndex = i;	
			}
		}

		// Is single matrix, return 0
		if (maxPivot == 0)
		{
			IsSingular = true;
			return 0;
		}

		// swap maxIndex row and k row, update coeff;
		if (k != maxIndex)
		{
			swap(A[k], A[maxIndex]);
			coeff *= (-1);
		}

		// eliminate all the row under pivot row
		for (int i = k + 1; i < n; ++i)
		{
			double c = (double)A[i][k]/(double)A[k][k];
			A[i][k] = 0.0;
			for (int j = k + 1; j < n; ++j)
			{
				A[i][j] -= c * A[k][j];
			}
		}
	}

	// mutiple all the elements in the main diag
	double ans = 1.0;
	for (int i = 0; i < n; ++i)
	{
		ans *= A[i][i];
	}
	ans *= coeff;

	return ans;
}

int main()
{
	// test 1
	int n = 2;
	vector<vector<int> > A(n, vector<int>(n, 0));
	A[0][0] = 1; A[0][1] = 2;
	A[1][0] = 3; A[1][1] = 4;
	int ans = MatrixDeterminant(A);
	cout << ans << endl;

	// test 2
	int n2 = 3;
	vector<vector<int> > A2(n2, vector<int>(n2, 0));
	A2[0][0] = -2; A2[0][1] = 2; A2[0][2] = -3;
	A2[1][0] = -1; A2[1][1] = 1; A2[1][2] = 3;
	A2[2][0] = 2;  A2[2][1] = 0; A2[2][2] = -1;
	int ans2 = MatrixDeterminant(A2);
	cout << ans2 << endl;

	return 0;
}
