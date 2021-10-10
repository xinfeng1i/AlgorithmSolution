//
//  1601_救生艇.cpp
//  HelloXcode
//
//  Created by xinfengli on 2021/10/10.
//

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;


/*
 * Method: 有序数组相向双指针
 *
 * 时间复杂度: O(nlogn)
 * 空间复杂度：O(1)
 */
int numRescueBoats(vector<int> &people, int limit) {
    sort(people.begin(), people.end());
    
    int ans = 0;
    int n = (int) people.size();
    int i = 0;
    int j = n - 1;
    
    while (i < j) {
        if (people[i] + people[j] > limit) {
            ans++;
            j--;
        } else {
            ans++;
            i++;
            j--;
        }
    }
    
    if (i == j) ans++;
    
    return ans;
}


#if 0
int main() {
    // expected: 1
    vector<int> people = {1, 2};
    int limit = 3;
    
    // expected: 3
    vector<int> people2 = {3, 2, 2, 1};
    int limit2 = 3;
    
    // expected: 4
    vector<int> people3 = {3, 5, 3, 4};
    int limit3 = 5;
    
    int ans = numRescueBoats(people3, limit3);
    printf("%d\n", ans);
    return 0;
}
#endif // 0
