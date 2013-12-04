// BEGIN CUT HERE

// END CUT HERE
#line 5 "MiniatureDachshund.cpp"
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
class MiniatureDachshund 
{
public:
	int maxMikan(vector <int> mikan, int weight) 
	{
        int curWeight = weight;
        sort(mikan.begin(), mikan.end());
        int cnt = 0; 

        for (int i = 0; i < mikan.size(); ++i)
        {
            if (curWeight + mikan[i] <= 5000)
            {
                cnt++;
                curWeight += mikan[i];
            }
            else
            {
                break;
            }
        }
        return cnt;

	}
};

// BEGIN CUT HERE  
int main()  
{  
        MiniatureDachshund ___test;  
        ___test.run_test(-1);  
        return 0;  
}  
// END CUT HERE 
