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

/**
* @param s: The first string
* @param b: The second string
* @return true or false
*/
bool anagram(string s, string t) {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}