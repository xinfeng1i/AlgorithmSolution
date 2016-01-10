#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int nthSuperUglyNumber(int n, vector<int>& primes){
    if (n <= 0) return -1;
    vector<long long> ugly(1, 1);
    
    vector<int> p(primes.size(), 0);
    while (ugly.size() < n) {
        long long nextUgly = ugly[p[0]] * (long long)primes[0];
        for (size_t i = 1; i < p.size(); ++i) {
            nextUgly = min(nextUgly, (long long)ugly[p[i]] * primes[i]);
        }
        
        ugly.push_back(nextUgly);
        
        for (size_t i = 0; i < p.size(); ++i) {
            if (nextUgly == ugly[p[i]] * (long long)primes[i]) {
                p[i]++;
            }
        }
    }
    
    return ugly[n-1];
}

int main()
{
    int a[] = {2, 7, 13, 19};
    vector<int> primes(a, a + 4);
    for (int n = 1; n <= 15; ++n) {
        cout << nthSuperUglyNumber(n, primes) << endl;
    }
    
    return 0;
}
