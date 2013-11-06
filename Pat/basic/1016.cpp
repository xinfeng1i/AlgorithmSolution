#include <iostream>
#include <string>
using namespace std;

long Pa(long A, int Da)
{
    long a[10];
    for (int i = 0; i < 10; ++i)
    {
        a[i] = 0;
    }

    while (A != 0)
    {
        int tmp = A % 10;
        a[tmp]++;
        
        A /= 10;
    }

    long cnt = a[Da];
    long ans = 0;
    while (cnt > 0)
    {
        ans = ans * 10 + Da;

        cnt--;
    }

    return ans;
}

int main()
{
    long a, b;
    int da, db;
    cin >> a >> da >> b >> db;
    long pa = Pa(a, da);
    long pb = Pa(b, db);
    cout << pa + pb << endl;
    return 0;
}
