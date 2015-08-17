#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#if 0
int main()
{
    int n = 0;
    int ch = 0;

    scanf("%d %c", &n, &ch);
    int rowNum = (int)round(n / 2.0);

    // first line
    for (int i = 0; i < n; ++i) printf("%c", ch);
    printf("\n");

    for (int j = 0; j < rowNum - 2; ++j)
    {
        printf("%c", ch);
        for (int i = 0; i < n - 2; ++i) printf(" ");
        printf("%c\n", ch);

    }

    // last line
    for (int i = 0; i < n; ++i) printf("%c", ch);
    printf("\n");

    return 0;
}
#endif //0
