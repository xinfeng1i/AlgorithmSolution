#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
     int  NumberOf1(int n) {
         int cnt = 0;
         while (n) {
             n = n & (n-1);
             cnt++;
         }
         return cnt;
     }
};
