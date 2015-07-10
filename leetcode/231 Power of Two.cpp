#include "MyHeaders.h" 

// Summary: Bit operator to count 1s in binary representation
bool isPowerOfTwo(int n)
{
    if (n <= 0) return false;

    int cnt = 0;
    while (n)
    {
        n &= (n-1);
        cnt++;
    }
    return cnt == 1;
}

#if 0
int main()
{
    while (1)
    {
        printf("Enter a N:\n");
        int n;
        scanf("%d", &n);

        printf("%d\n", isPowerOfTwo(n));
    }
    return 0;
}
#endif //0