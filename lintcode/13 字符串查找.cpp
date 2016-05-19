#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <unordered_set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int strStr(const char *source, const char *target) {
	// 注意检测指针的合法性: p != NULL
	if (source == NULL || target == NULL) return -1;
    int n1 = strlen(source);
    int n2 = strlen(target);
    if (n2 > n1) return -1;
    for (int i = 0; i <= n1-n2; i++) {
        bool found = true;
        for (int k = 0; k < n2; ++k) {
            if (source[i+k] == target[k]) {
                continue;
            } else {
                found = false;
                break;
            }
        }
        if (found == true) {
            return i;
        }

    }

    return -1;
}

int main()
{
	char s[] = "";
	char e[] = "a";
	cout << strStr(NULL, e) << endl;
	return 0;
}
