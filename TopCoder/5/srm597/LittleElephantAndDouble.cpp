#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

class LittleElephantAndDouble 
{
public:
string getAnswer(vector<int> A)
{
    int max = *max_element(A.begin(), A.end());
    for (int i = 0; i < A.size(); ++i)
    {
        // WARNING:
        // either equal the max or divisible by max, the 
        // answer can also divisible by 2, return YES
        if ( max != A[i] && !(max % A[i] == 0 && (max / A[i]) % 2 == 0) )
        {
            return "NO"; 
        }
    }
    return "YES";
}
};


// Summary:
// the original condition is like
// *******************************************
// * max / A[i] == 1 || (max / A[i]) % 2 == 0
// *******************************************
// which is WRONG, because if 5 / 3 also equals 1, this condition 
// neglect that the division between integer is not accurate
// the right condition is that:
// *************************************************************
// * the element is either equals the max, or the max is divisible 
// * the element && (max / element) % 2 == 0
// *  !( max == A[i] || (max % A[i] == 0 && (max / A[i]) % 2 == 0) )
// * which is equaivent to
// * max != A[i] && !(max % A[i] == 0 && (max / A[i]) % 2 == 0)
// 
// python27
// 2013/11/22
