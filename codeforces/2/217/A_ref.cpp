#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    //rook
    if (r1 == r2 || c1 == c2)
    {
        cout << 1;
    }
    else
    {
        cout << 2;
    }

    cout << " ";


    // bishop
    // if on the same diag, then it must be that
    // k = (y1 - y2) / (x1 - x2) = 1 or -1
    // then |y1 - y2| == (x1 - x2)
    //
    // if they can be reached by the diag, then if 
    // we number them by (x + y), then there must be
    // that (x2 + y2) and (x1 + y1) can diff 2 * k, k is 1,2,3....
    //
    // Remember it, this problem have been encounted many times.
    if ( abs(c1 - c2) == abs(r1 - r2) )
    {
        cout << 1;
    }
    else if ( (r1 + c1) % 2 != (r2 + c2) % 2)
    {
        cout << 0;
    }
    else
    {
        cout << 2;
    }

    cout << " ";

    // king
    cout << max(abs(r1 - r2), abs(c1 - c2));
    cout << endl;

    return 0;
}
