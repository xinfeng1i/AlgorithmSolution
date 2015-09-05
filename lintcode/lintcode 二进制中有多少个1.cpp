#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <iterator>
using namespace std;

int countOnes(int num) {
    int cnt = 0;
    while (num != 0) {
        num = num & (num - 1);
        cnt++;
    }
    return cnt;
}

#if 0
int main()
{
    cout << countOnes(8) << endl;
    return 0;
}
#endif //0