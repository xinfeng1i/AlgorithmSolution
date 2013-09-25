#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    string input;
    cin >> input;
    int sz = input.size();
    int n1 = (sz + 2) / 3 - 1;
    int n2 = sz - 2 * n1;
    string space(n2 - 2, ' ');
    for (int i = 0, j = sz - 1; i < n1; ++i, --j)
    {
        cout << input[i] << space << input[j] << endl;
    }

    cout << input.substr(n1, n2) << endl;
    return 0;
}

// infer length of n1, n2, n3
// n1 = n3 = k <= n2
// n1 + n2 + n3 = N + 2 = 2 * k + n2
// n2 = N + 2 - 2*k >= k
// so n1 = n2 = k <= (N + 2) / 3 OR N + 2 <= 3 * n2 => n2 >= (N + 2) / 3
// if choose latter, the N - n2 will possible be odd, difficult to handle
// so choose first way.
// Be Careful about everything.
