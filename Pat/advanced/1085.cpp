#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
using namespace std;

#if 0
int main()
{
    int n;
    double p;
    cin >> n >> p;
    vector<double> v(n, 0);
    int i;
    for (i = 0; i < n; ++i) cin >> v[i];

    sort(v.begin(), v.end());

    int length = -1;
    for (i = 0; i < n; ++i) {
        vector<double>::iterator it1, it2;
        double minVal = v[i];
        double maxVal = minVal * p;
        it1 = v.begin() + i;
        it2 = upper_bound(v.begin(), v.end(), maxVal);
        if (it2 - it1 > length)
            length = it2 - it1;

        // speed up the search, if minVal is v[i], the maxVal is end()
        // then when i++, the maxVal is still end(), the length will shrink
        // there is no need to continue searching
        if (it2 == v.end())
            break;
    }
    
    cout << length << endl;
    
    return 0;
}
#endif //0