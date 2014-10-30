#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

double QuickSqrtAlgorithm(double a)
{
    const double EPS = 0.000001;
    
    double x = 1.0;
    double left = a / x;
    double right = x;
    while (abs(left - right) > EPS)
    {
        x = (left + right) / 2.0;
        left = a / x;
        right = x;
    }

    return x;
}

int main()
{
    double a;
    cin >> a;
    cout << QuickSqrtAlgorithm(a) << endl;
    return 0;
}
