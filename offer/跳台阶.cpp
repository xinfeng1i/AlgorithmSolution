#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int jumpFloor(int n) {
        int a = 1;
        int b = 1;
        
        int i = 0;
        while (i++ < n) {
            int c = a + b;
            a = b;
            b = c;
        }
        
        return a;    
    }
};
