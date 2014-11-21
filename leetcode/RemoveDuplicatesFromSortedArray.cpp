#include <iostream>
#include <string>
using namespace std;

int removeDuplicates(int A[], int n)
{
    if (n <= 1) return n;

    int cur = 0;
    int pos = 1;
    while (cur < n)
    {
        int next = cur + 1;
        while (next < n && A[next] == A[cur]) next++;

        if (next >= n)
        {
            cur = next;
        }
        else if (next < n && A[next] != A[cur])
        {
            A[pos++] = A[next];
            cur = next;
        }
    }

    return pos;
}

int main()
{
    int A[] = {1, 1, 2, 3, 3, 4};
    int len = removeDuplicates(A, 6);
    for (int i = 0; i < len; ++i)
    {
        cout << " " << A[i];
    }
    cout << endl;

    return 0;
}
