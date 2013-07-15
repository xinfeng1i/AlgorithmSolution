#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

const int GRID_SIZE = 20;

int main()
{
    int grid[GRID_SIZE][GRID_SIZE];
    ifstream fin;
    fin.open("Problem#11_data.txt");
    if (!fin.is_open())
    {
        cerr << "Cannot Open File: Problem#11_data.txt" << endl;
        cerr << "Please Check Your Filename" << endl;
        return -1;
    }
    // Read data from file into array 'grid'
    for (size_t i = 0; i < GRID_SIZE; i++)
    {
        for (size_t j = 0; j < GRID_SIZE; j++)
        {
            fin >> grid[i][j];
        }
    }

    fin.close();

    #if 1 // check whether read successfully
    for (size_t i = 0; i < GRID_SIZE; i++)
    {
        for (size_t j = 0; j < GRID_SIZE; j++)
        {
            cout << " " <<  grid[i][j];
        }
        cout << endl;
    }
    #endif //
    
    long long maxProduct = 0;
    long long curProduct = 0;

    // find maxProduct from rows
    for (size_t i = 0; i < GRID_SIZE; i++)
    {
        for (size_t j = 0; j <= GRID_SIZE - 4; j++)
        {
            curProduct = grid[i][j] * grid[i][j+1] * grid[i][j+2] * grid[i][j+3];
            if (curProduct > maxProduct)
            {
                maxProduct = curProduct;
            }
        }
    }
    cout << "Rows" << endl;
    
    // find maxProduct from cloumns
    for (size_t j = 0; j < GRID_SIZE; j++)
    {
        for (size_t i = 0; i <= GRID_SIZE - 4; i++)
        {
           curProduct = grid[i][j] * grid[i+1][j] * grid[i+2][j] * grid[i+3][j]; 
           if (curProduct > maxProduct)
           {
                maxProduct = curProduct;
           }
        }
    }
    cout << "cloumns " << endl;

    // find maxProduct from positive diagonal
    for (size_t i = 0; i < GRID_SIZE; i++)
    {
        for (size_t j = 0; j < GRID_SIZE; j++)
        {
            if (i + 3 < GRID_SIZE && j + 3 < GRID_SIZE)
            {
                curProduct = grid[i][j] * grid[i+1][j+1] * grid[i+2][j+2] * grid[i+3][j+3];
                if (curProduct > maxProduct)
                {
                    maxProduct = curProduct;
                }
            }
        }
    }
    cout << "positive diagonal" << endl;

    // find maxProduct from negative diagonal
    for (size_t i = GRID_SIZE - 1; i >= 0; i--)
    {
        for (size_t j = 0; j < GRID_SIZE; j++)
        {
            if (i - 3 >= 0 && j + 3 < GRID_SIZE)
            {
                curProduct = grid[i][j] * grid[i-1][j+1] * grid[i-2][j+2] * grid[i-3][j+3];
                if (curProduct > maxProduct)
                {
                    maxProduct = curProduct;
                }
            }
        }
    }
    cout << "negative diagonal" << endl;
    
    cout << "The Max Product in Grid[20,20] is:" << maxProduct << endl;

    return 0;
}
