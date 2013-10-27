#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    long long n = 0;
    cin >> n;

    long long count = 0;
    long long dfactor = 10;
    long long factor = 1;
    while (true)
    {
        // compute up to this digit how many 1s have cost
        count += (n / dfactor) * factor;

        // add the extra
        if (n % dfactor >= 2 * factor)
        {
            count += factor;
        }
        else if (n % dfactor >= 1 * factor)
        {
            count += (n % dfactor) - factor + 1;
        }

        if (dfactor > n)
        {
            break;
        }

        dfactor *= 10;
        factor *= 10;
    }

    cout << count << endl;
}
