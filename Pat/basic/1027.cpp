#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int n;
    char ch;
    cin >> n >> ch;

    int k = (int)sqrt((n+1)*2.0) - 1;

    //必须保证得到的k为奇数
    if (k % 2 == 0) k = k - 1;

    int cnt = 0;
    for (int i = k; i >= 1; i -= 2)
    {
        int nspace = (k - i) / 2;
        cout << string(nspace, ' ');
        cout << string(i, ch) << endl;
        cnt += i;
    }

    for (int i = 3; i <= k; i += 2)
    {
        int ns = (k - i) / 2;
        cout << string(ns, ' ');
        cout << string(i, ch) << endl;
        cnt += i;
    }

    int r = n - cnt;
    cout << r << endl;
    return 0;
}
