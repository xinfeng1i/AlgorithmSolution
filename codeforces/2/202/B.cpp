#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    long totalv;
    cin >> totalv;
    long a[10] = {0};
    for (int i = 1; i < 10; ++i)
    {
        cin >> a[i];
    }

    long minv = *min_element(a + 1, a + 10); 
    
    // special case: min_v > totalv
    // return -1
    if (totalv < minv)
    {
        cout << -1 << endl;
        return 0;
    }

    long digit_num = totalv / minv;
    long remainder = totalv % minv; 
    for (int i = 0; i < digit_num; ++i)
    {
        int k = 9;
        while (k >= 0 && a[k] >  minv + remainder)
        {
            k--;
        }
        remainder = minv + remainder - a[k];
        cout << k;

    }
    cout << endl;
    return 0;
}

// I almost catch the whole idea, so close.
//
// Main Idea:
// choose digit which cost least paint, to contain more digits, thus make
// the number more big, calculate the number of digits, total paint divide
// the chosen digit, which may still have 0, 1, 2, ..., digit-1 paint
// for 9 to 1 to check if we can paint the larger number.
//
// the tag of the problem is DP, Greedy, Binay Search
// But I cannot find any clue about that
