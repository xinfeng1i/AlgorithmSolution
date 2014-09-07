#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
#include <ctime>

using namespace std;

long PentagonNumber(long n)
{
    assert(n >= 1);
    return n * (3 * n - 1) / 2;
}


int main()
{
    clock_t time_begin = clock();

    vector<long> penNumbers;
    for (long i = 1; i <= 10000; i++)
    {
        penNumbers.push_back(PentagonNumber(i)); 
    }
    
    for (long i = 0; i < penNumbers.size(); i++)
    {
        for(long j = i + 1; j < penNumbers.size(); j++)
        {
            if (binary_search(penNumbers.begin(), penNumbers.end(), 
                        penNumbers[i] + penNumbers[j]) && 
                binary_search(penNumbers.begin(), penNumbers.end(),
                        penNumbers[j] - penNumbers[i]) )
            {
                cout << "j = " << i + 1 << "    " << "k = " << j + 1 << endl;
                cout << "Sum: " << penNumbers[i] + penNumbers[j] << endl;
                cout << "Difference: " << penNumbers[j] - penNumbers[i] << endl;
            }
        }
    }

    clock_t time_end = clock();
    double time_cost = (double)(time_end - time_begin) / CLOCKS_PER_SEC;
    cout << "TIME COST: " << time_cost << " seconds" << endl;

    return 0;
}
