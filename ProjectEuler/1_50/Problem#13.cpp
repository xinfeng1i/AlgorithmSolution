#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

const int MAX_COL = 50;
const int MAX_ROW = 100;
const int MAX_DIGITS = 55;

int main()
{
    clock_t time_begin = clock();

    // open file
    ifstream fin("Problem#13_data.txt", ios_base::in);
    if (!fin.is_open())
    {
        cerr << "Cannot Open Problem#13_data.txt" << endl;
        cerr << "Please Check your filename." << endl;
        return -1;
    }

    /* Store BIG NUMBERs into an ARRAY 'digits' */
    // store the BIG NUMBER from low to high
    // for example: number 123 store as a[0] = 3, a[1] = 2, a[2] = 3
    int digits[MAX_ROW][MAX_COL];   
    string line;
    int row_cnt = -1;
    while (!fin.eof())
    {
        getline(fin, line);

        row_cnt++;
        for (int i = 0; i < line.size(); i++)
        {
            digits[row_cnt][MAX_COL-1-i] = line[i] - '0';
        }

    }
    fin.close();

    
    // add all digits without carry-bit
    int result[MAX_DIGITS] = {0};
    for (int j = 0; j < MAX_COL; j++)
    {
        for (int i = 0; i < MAX_ROW; i++)
        {
            result[j] += digits[i][j];
        }
    }
    
    // handle carry-bit number
    for (int j = 0; j < MAX_DIGITS; j++)
    {
        if (result[j] >= 10)
        {
            result[j+1] += result[j] / 10;
            result[j] = result[j] % 10;
        }
    }

    cout << "The Sum Number is: " << endl;
    int noZerobit = MAX_DIGITS - 1;
    while (result[noZerobit] == 0)
    {
        noZerobit--;
    }
    for (int j = noZerobit; j >= 0; j--)
    {
        cout << result[j];
    }
    cout << endl;

    cout << "The First 10 Digits of Sum is: " << endl;
    for (int j = noZerobit; j >= noZerobit - 10 + 1; j--)
    {
        cout << result[j];
    }
    cout << endl;

    clock_t time_end = clock();
    double time_cost = (double)(time_end - time_begin) / CLOCKS_PER_SEC;
    cout << "TIME COST:" << time_cost << " s" << endl;

    return 0;
}

