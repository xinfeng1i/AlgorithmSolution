#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    long a = 0;
    long b = 0;
    long c = 0;
    cin >> a >> b >> c;

    long x = 0;
    long y = 0;
    long z = 0;
    if ((a - b + c) % 2 == 0 && (-a + b + c) % 2 == 0 && (a + b -c) % 2 == 0)
    {
        x = (a + b - c) / 2;
        y = (-a + b + c) / 2;
        z = (a - b + c) / 2;

        if (   x >= 0 && x <= min(a, b)
            && y >= 0 && y <= min(b, c)
            && z >= 0 && z <= min(a, c))
        {
            cout << x << " " << y << " " << z << endl;
            return 0;
        }
    }

    cout << "Impossible" << endl;
    return 0;
}
