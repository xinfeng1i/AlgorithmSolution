#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string getAnswer(vector<int> A)
{
    int max = max_element(A.begin(), A.end());
    for (int i = 0; i < A.size(); ++i)
    {
        if ( (max / A[i]) != 1 && (max / A[i]) % 2 != 0 )
        {
            return "NO"; 
        }
    }
    return "YES";
}

int main()
{
    return 0;
}
