#include <iostream>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>

using namespace std;

/*
 * judge whether a number is prime
 */
bool isPrime(long long n)
{
    assert(n >= 1);
    long long i = 2;
    for(i = 2; i <= n/2; i++)
    {
        if (n % i == 0)
        {
            break;
        }
    }

    if (i <= n/2)
        return false;
    else
        return true;

}

int main()
{
    // test isPrime Function
    #if 0
    cout << "2 is Prime ? " << isPrime(2) << endl;
    cout << "10 is Prime ? " << isPrime(10) << endl;
    cout << "19 is Prime ? " << isPrime(19) << endl;
    #endif //
    
    clock_t time_begin = clock();

    cout << "Enter a rank number: ";
    long long n;
    cin >> n;
    long long cnt = 1;
    long long prime = 2;
    while (cnt < n)
    {
        prime++;
        if (isPrime(prime))
        {
            cnt++;
        }
    }
    cout << "the "<< n << "th Prime number is: " << prime << endl;

    clock_t time_end = clock();
    double time_cost = (double)(time_end - time_begin)/CLOCKS_PER_SEC;
    cout << "TIME COST:" << time_cost << " s" << endl;

    return 0;
}
