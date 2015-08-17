#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    long galleon = 0; //
    long sickle = 0;  // 17
    long knut = 0; // 29

    long galleon2 = 0; 
    long sickle2 = 0;  
    long knut2 = 0; 

    scanf("%ld.%ld.%ld %ld.%ld.%ld", &galleon, &sickle, &knut, &galleon2, &sickle2, &knut2);
    long tot1 = galleon * 17 * 29 + sickle * 29 + knut;
    long tot2 = galleon2 * 17 * 29 + sickle2 * 29 + knut2;
    long ans = tot2 - tot1;

    if (ans < 0) { ans = -ans; printf("-"); } 

    long a = ans / (17 * 29);
    long b = (ans % (17 * 29)) / 29;
    long c = (ans % (17 * 29)) % 29;
    printf("%ld.%ld.%ld\n", a, b, c);

    return 0;
}