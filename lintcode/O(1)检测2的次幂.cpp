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

/*
 * @param n: An integer
 * @return: True or false
 */
bool checkPowerOf2(int n) {
    if (n <= 0) return false;
    return (n & (n - 1)) == 0;
}