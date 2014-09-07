#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <algorithm>

using namespace std;

const int MATRIX_SIZE = 15;

int main()
{
    clock_t time_begin = clock();

    int a[MATRIX_SIZE][MATRIX_SIZE] = {0};

    // open file, store matrix into array 'a'
    ifstream fin("Problem#18_data.txt", ios_base::in); 
    if (fin.is_open())
    {
        for (int i = 0; i < MATRIX_SIZE; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                    fin >> a[i][j];
            }
        }

        fin.close();
    }
    else
    {
        cerr << "Cannot Open File ! Please Check Your Filename" << endl;
    }

    /* Greedy Algorithm
     * If we know the top to ith layer max path sum; for every number
     * in i+1 th layer, we choose the max adjacent max path sum above, 
     * add it the number. 
     * we got the the top to i+1 th layer max path sum
     */
    int maxPathSum[MATRIX_SIZE][MATRIX_SIZE] = {0};
    maxPathSum[0][0] = a[0][0];
    for (int i = 1; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            int preLeftMaxPathSum = 0;
            int preMidMaxPathSum = 0;
            if (j - 1 >= 0)
            {
                preLeftMaxPathSum = maxPathSum[i-1][j-1];
            }
            preMidMaxPathSum = maxPathSum[i-1][j];

            int tmpMax = max(preLeftMaxPathSum, preMidMaxPathSum);
            
            maxPathSum[i][j] = a[i][j] + tmpMax;
        }
    }

    
    cout << "The Last Row:" << endl;
    int result = 0;
    for (int j = 0; j < MATRIX_SIZE; j++)
    {
        cout << maxPathSum[MATRIX_SIZE-1][j] << " ";
        if (maxPathSum[MATRIX_SIZE-1][j] > result)
        {
            result = maxPathSum[MATRIX_SIZE-1][j];
        }
    }
    cout << endl;
    cout << "The Max Path Sum: " << result << endl;

    clock_t time_end = clock();
    double time_cost = (double)(time_end - time_begin) / CLOCKS_PER_SEC;
    cout << "TIME COST: " << time_cost << " s" << endl;
    return 0;
}
