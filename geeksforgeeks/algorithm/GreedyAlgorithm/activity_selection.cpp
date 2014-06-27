#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
using namespace std;

/* Problem Statement --- Activity Selection:
 * Given n activities with start time and end time, select the maximum
 * number of activities that can be performed by a single person, assuming 
 * that a person can only work on a single activity at a time
 */

/* Algorithm Steps:
 * 1. sort the activities by end time
 * 2. Always select the activity whose start time is greater than the end 
 *    time of prevously selected one.
 */


// Assuming that the f[] is already sorted
void ActivitySelection(int s[], int f[], int n)
{
    int cur = 0;
    printf("activity: %d, Time: %d - %d\n", cur, s[cur], f[cur]);
    for (int i = 1; i < n; ++i)
    {
        if (s[i] >= f[cur])
        {
            cur = i;
            printf("activity: %d, Time: %d - %d\n", cur, s[cur], f[cur]);
        }
    }
}

// Proof:
// if the sorted f is f = {1, 2, 3,...,n}
// then every time we always pick 1. If there is a solution B not pick 1,
// let's say {k, 4, 9, 10}, Then we can also get a solution A with pick 1,
// A = B - {k} + {1}. Why ? Since k is the first activity picked, then we 
// have f[k] <= f[i] (i \in B), also we have f[1] is the smallest, so we 
// f[1] <= f[k] <= f[i] (i \in B). So if we replace k with 1, then we can
// get a solution.

int main()
{
    int s[] = {1, 3, 0, 5, 8, 5};
    int f[] = {2, 4, 6, 7, 9, 9};
    int n = sizeof(s) / sizeof(s[0]);

    ActivitySelection(s, f, n);

    return 0;
}
