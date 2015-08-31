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
* @param key: A String you should hash
* @param HASH_SIZE: An integer
* @return an integer
*/
int hashCode(string key, int HASH_SIZE) {
    const int PRIME = 33;
    long long int coeff = 1;
    long long sum = 0;
    for (auto it = key.rbegin(); it != key.rend(); ++it) {
        int ch = *it;
        
        sum = (sum % HASH_SIZE +
            ((ch % HASH_SIZE) * (coeff % HASH_SIZE)) % HASH_SIZE) % HASH_SIZE;
        //cout << *it << "   sum = " << sum << " coeff = " << coeff << endl;

        coeff = ((coeff % HASH_SIZE) * (PRIME % HASH_SIZE)) % HASH_SIZE;
    }
    return sum;
}

// 使用 long long 避免整型溢出.

int main()
{
    cout << hashCode("Wrong answer or accepted?", 1000000007) << endl;
    return 0;
}