#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
using namespace std;

string isPossible(vector<int> values)
{
    int n = values.size();
    const int LIMIT = 30000;
    set<int> coeffs;
    for (int x = 1; x < LIMIT; ++x)
    {
        int tmp = x;
        coeffs.clear(); 
        for (int i = n - 1; i >= 0; --i)
        {
            int c = tmp / values[i];
            coeffs.insert(c);
            tmp -= c * values[i];
        }
        
        if ( count_if(coeffs.begin(), coeffs.end(), bind2nd(greater<int>(),0) ) == n)
        {
            return "Possible";
        }
    }

    return "Impossible";

}

int main()
{
    cout << "vector size: " << endl;
    int n;
    cin >> n;

    cout << "Input elems :" << endl;
    vector<int> v(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
    
    cout << "Result: " << isPossible(v) << endl;
    return 0;
}

