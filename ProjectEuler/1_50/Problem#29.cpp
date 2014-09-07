#include <iostream>
#include <string>
#include <set>
#include <cmath>

using namespace std;

const int UP_BOUND = 100;
const int LOW_BOUND = 2;
const double EPSION = 0.0000000000001;

bool isEqual(double x, double y)
{
    if (abs(x - y) <= EPSION)
        return true;
    else
        return false;
}

int main()
{
    set<double> s;
    int total_number = (UP_BOUND - LOW_BOUND + 1) * (UP_BOUND - LOW_BOUND + 1);
    int equal_number = 0;
    for (int a = LOW_BOUND; a <= UP_BOUND; ++a)
    {
        for(int b = LOW_BOUND; b <= UP_BOUND; ++b)
        {
            if ( a != b && isEqual(b * log2(static_cast<double>(a)),  
                                   a * log2(static_cast<double>(b)) ) )
            {
                cout << "a=" << a << " b=" << b << endl;
                equal_number++;
            }
        }
    }

    cout << "total: " << total_number << endl;
    cout << "equal: " << equal_number << endl;
    cout << "The Number of distinct elements: " 
    << total_number - equal_number/2  << endl;
    return 0;
}
