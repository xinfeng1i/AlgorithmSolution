#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
* @param x: An integer
* @return: The sqrt of x
*/
int sqrt(int x) {
    const double EPS = 0.00001;
    double left = 1.0;
    double right = x / left;
    while (abs(left - right) > EPS) {
        left = (left + right) / 2.0;
        right = x / left;
    }
    return static_cast<int>(left);
}

#if 0
int main()
{
    cout << sqrt(10) << endl;
    return 0;
}
#endif //0