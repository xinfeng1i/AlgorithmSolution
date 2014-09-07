#include <iostream>
#include <string>
#include "BigIntegerLibrary.hh"
using namespace std;

// This Problem used 3rd-party library - C++ Big Integer Library
// You can find this library according to the link below
// https://mattmccutchen.net/bigint/
//
// You can compile and run the program by the following three commands:
//    ***************************************************************
//    *  g++ -I ../bigint/ -c Problem#57.cpp                        *
//    *  g++ -o Problem#57 -I ../bigint/ Problem#57.o ../bigint/*o  *
//    * ./Problem#57                                                *
//    ***************************************************************
//
int main()
{
    BigInteger n(1);
    BigInteger d(1);
    BigInteger tmp(0);
    BigInteger expansion_times(0);
    BigInteger ans(0);
    do{
        tmp = n + d;
        n = tmp + d;
        d = tmp;
        expansion_times++;
        if (bigIntegerToString(n).size() > bigIntegerToString(d).size())
        {
            ans++;
        }
    }while (expansion_times < 1000);
    cout << "ans is : " << ans << endl;
    cout << "final fraction is: " << n << "/" << d << endl;
    return 0;
}

// Summary:
// This is the first time I use big integer library to solve problems.
// It is convenient in many ways. 
// But avoid it as much as you can, because there may be some fancy algorithms
// to solve the same problem elegantly
// Python27
