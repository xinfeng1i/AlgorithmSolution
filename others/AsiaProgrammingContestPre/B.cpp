#include <iostream>
#include <string>
using namespace std;

int main()
{
    string A;
    unsigned long long B;
    cin >> A >> B;
    unsigned long long asize = A.size();
    unsigned long long r = B % asize;
    if (r == 0) r += asize;
    cout << A[r-1] << endl;
    return 0;
}
