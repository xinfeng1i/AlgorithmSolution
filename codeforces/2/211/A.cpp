#include <iostream>
#include <cstdio>
#include <cassert>
#include <string>
#include <vector>
using namespace std;

void printDigit(int d)
{
    //assert(d >= 0 && d <= 9)
    switch(d)
    {
        case 0: printf("O-|-OOOO\n");
                break;
        case 1: printf("O-|O-OOO\n");
                break;
        case 2: printf("O-|OO-OO\n");
                break;
        case 3: printf("O-|OOO-O\n");
                break;
        case 4: printf("O-|OOOO-\n");
                break;
        case 5: printf("-O|-OOOO\n");
                break;
        case 6: printf("-O|O-OOO\n");
                break;
        case 7: printf("-O|OO-OO\n");
                break;
        case 8: printf("-O|OOO-O\n");
                break;
        case 9: printf("-O|OOOO-\n");
                break;
        default:printf("Wrong parameter\n");
                break;
    }

    return;
}

int main()
{
    long long n;
    cin >> n;
    
    if (n == 0)
    {
        printDigit(0);
        return 0;
    }

    int tmp = 0;
    while (n != 0)
    {
        tmp = n % 10;
        printDigit(tmp);
        n /= 10;
    }

    return 0;
}
