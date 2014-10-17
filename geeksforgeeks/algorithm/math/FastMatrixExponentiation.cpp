#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * Return A * B, use Naive algorithm, O(n^3)
 * -------
 * INPUT : A, B - square matrix with same order
 * OUTPUT: A * B
 */
vector<vector<int> > MatrixMultiplication(const vector<vector<int> >& A, const vector<vector<int> >& B)
{
	int n = A.size();
	vector<vector<int> > C(n, vector<int>(n, 0));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			C[i][j] = 0;
			for (int k = 0; k < n; ++k)
			{
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	return C;
}

/**
 * Return A^k
 * ----------
 * INPUT : A - square matrix
 * OUTPUT: A^k
 * ----------
 * Fast exponentitation algorithm is used. O(n^3*logk)
 */
vector<vector<int> >FastMatrixExponentiation(vector<vector<int> > A, int k)
{
	int n = A.size();

	// init, ans is E matrix
	vector<vector<int> > ans(n, vector<int>(n, 0));
	for (int i = 0; i < n; ++i) ans[i][i] = 1;

	while (k > 0)
	{
		if (k % 2 == 0)
		{
			// double A, half exp k
			A = MatrixMultiplication(A, A);
			k /= 2;
		}
		else
		{
			// write one A to ans, exp--
			ans = MatrixMultiplication(ans, A);
			k--;
		}
	}
	return ans;
}

void PrintMatrix(const vector<vector<int> >& A)
{
	int n = A.size();
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << A[i][j] << "\t";
		}
		cout << "\n";
	}
	cout << "\n\n";
}

int main()
{
	vector<vector<int> > A(3, vector<int>(3, 0));
	A[0][0] = 1; A[0][1] = 2; A[0][2] = 3;
	A[1][0] = 4; A[1][1] = 5; A[1][2] = 6;
	A[2][0] = 7; A[2][1] = 8; A[2][2] = 9;

	PrintMatrix(FastMatrixExponentiation(A, 3));
	return 0;
}
