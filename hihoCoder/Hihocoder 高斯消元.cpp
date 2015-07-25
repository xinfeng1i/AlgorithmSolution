#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <numeric>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cctype>
using namespace std;



typedef double llong;
int main()
{
    //freopen("input.txt", "r", stdin);
    int N, M;
    cin >> N >> M;
    vector<vector<llong> > A(M, vector<llong>(N, 0));
    vector<llong> b(M, 0);

    // INPUT
    int pivotIndex, i, j, k;
    for (i = 0; i < M; ++i)
    {
        for (j = 0; j < N; ++j)
        {
            cin >> A[i][j];
        }
        cin >> b[i];
    }


    bool foundPivot = false;
    for (pivotIndex = 0; pivotIndex < N; ++pivotIndex)
    {
        foundPivot = false;
        for (i = pivotIndex; i < M; ++i)
        {
            if (A[i][pivotIndex] != 0)
            {
                swap(A[i], A[pivotIndex]);
                swap(b[i], b[pivotIndex]);
                foundPivot = true;
                break;
            }
        }

        if (foundPivot == false)
        {
            cout << "Many solutions" << endl;
            return 0;
        }
        
        // Gaussian       
        llong pivot = A[pivotIndex][pivotIndex];
        for (i = pivotIndex + 1; i < M; ++i)
        {
            // Need to Store coeff to avoid varies
            llong coeff = A[i][pivotIndex];
            for (k = 0; k < N; ++k)
            {
                A[i][k] += - A[pivotIndex][k] * coeff / pivot ;
            }

            b[i] += -b[pivotIndex] * coeff / pivot ;
        }       
    }

    // No solution
    for (i = 0; i < M; ++i)
    {
        bool ZeroRow = true;;
        for (j = 0; j < N; ++j)
        {
            if (A[i][j] != 0)
            {
                ZeroRow = false;
            }
        }

        if (ZeroRow && b[i] != 0)
        {
            cout << "No solutions" << endl;
            return 0;
        }
    }

    // Only One Solution   
    for (i = N - 1; i >= 0; --i)
    {        
        for (k = N - 1; k > i; --k)
        {
            b[i] -= b[k] * A[i][k];
            A[i][k] = 0;
        }

        b[i] = (b[i]) / A[i][i];
    }

    for (i = 0; i < N; ++i)
    {
        cout << b[i] << endl;
    }

    return 0;
}

