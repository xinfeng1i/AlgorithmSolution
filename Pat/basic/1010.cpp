#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Method 1: my method, too trival, not elegant
/*
int main()
{
    vector<int> numbers;
    int n = 0;
    while (cin >> n)
    {
        numbers.push_back(n);
    }
    int sz = numbers.size();
    if (sz <= 2)
    {
        if (numbers[0] * numbers[1] == 0)
        {
            cout << 0 << " " << 0 << endl;
        }
        else
        {
            cout << numbers[0] * numbers[1] << " " << numbers[1] - 1 << endl;
        }
    }
    else
    {
#if 0
        // will have extra space at the very begining of the output
        if (numbers[0] * numbers[1] != 0)
        {
            cout << numbers[0] * numbers[1] << " " << numbers[1] - 1;
        }
        for (int i = 2; i < numbers.size(); i += 2)
        {
            int a = numbers[i];
            int b = numbers[i+1];
            if (a * b != 0)
            {
                cout << " " << a * b  << " " << b - 1;
            }
        }
#endif
        // this will solve the problem good, but the code is too ugly
        int i = 0;
        while (numbers[i] * numbers[i+1] == 0)
        {
            i += 2;
        }
        cout << numbers[i] * numbers[i+1] << " " << numbers[i+1] - 1;
        i += 2;
        for (; i < sz; i += 2)
        {
            if (numbers[i] * numbers[i+1] != 0)
            {
                cout << " " << numbers[i] * numbers[i+1] << " " << numbers[i+1] - 1;
            }
        }
        cout << endl;
    }

    return 0;
}
*/

// method 2: other's more elegant code, need learn how to control output format
int main()
{
    int a, b;
    bool flag = false; // indicate that whether there are a pair of nonzeros
                       // terms in the output sequence
    while (cin >> a >> b)
    {
        if (a * b)
        {
            if (flag)   // already have some non zeros pairs, add a space
            {
                cout << " ";
            }
            else
            {
                flag = true;  // no non-zero pairs before, this is the first
                              // reset the flag true, output itself
            }
            cout << a * b << " " << b - 1;
        }
    }
    
    if (!flag) // still have non-zeros pairs, is a constant, output 0 0;
    {
        cout << 0 << " " << 0;
    }
    cout << endl;
    return 0;
}
