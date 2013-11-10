// BEGIN CUT HERE

// END CUT HERE
#line 5 "NoOrderOfOperations.cpp"
#include <cstdlib>  
#include <cctype>  
#include <cstring>  
#include <cstdio>  
#include <cmath>  
#include <algorithm>  
#include <vector>  
#include <string>  
#include <iostream>  
#include <sstream>  
#include <map>  
#include <set>  
#include <queue>  
#include <stack>  
#include <fstream>  
#include <numeric>  
#include <iomanip>  
#include <bitset>  
#include <list>  
#include <stdexcept>  
#include <functional>  
#include <utility>  
#include <ctime>  
using namespace std;
class NoOrderOfOperations 
{
public:
	int evaluate(string expr) 
	{
        int ans = expr[0] - '0';
        int cur = 1;
        int next = cur + 1;
        while (cur < expr.size() && next < expr.size())
        {
            switch (expr[cur])
            {
                case '+': ans += expr[next] - '0';
                          break;
                case '-': ans -= expr[next] - '0';
                          break;
                case '*': ans *= expr[next] - '0';
                          break;
            }

            cur++;
            next++;
        }

        return ans;
	}
};

// BEGIN CUT HERE  
int main()  
{  
        NoOrderOfOperations ___test;  
        ___test.run_test(-1);  
        return 0;  
}  
// END CUT HERE 
