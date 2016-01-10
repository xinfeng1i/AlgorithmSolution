#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isPowerOfThree(int n) {
    if (n <= 0) return false;
    while (n % 3 == 0) {
        n /= 3;
    }
    return (n==1);
}