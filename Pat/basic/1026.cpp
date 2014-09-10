#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;

int main()
{
    long c1, c2;
    cin >> c1 >> c2;
    long s = lround((c2 - c1) / 100.0);
    long hh = s / 3600;
    long mm = s % 3600 / 60;
    long ss = s % 60;
    //cout << hh << ":" << mm << ":" << ss << endl;
    printf("%02ld:%02ld:%02ld\n", hh, mm, ss);
    return 0;
}
