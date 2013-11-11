// BEGIN CUT HERE

// END CUT HERE
#line 5 "PassingGrade.cpp"
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
class PassingGrade 
{
public:
	int pointsNeeded(vector <int> pointsEarned, 
                     vector <int> pointsPossible, int finalExam) 
	{
        int currentPoints = accumulate(pointsEarned.begin(), 
                                       pointsEarned.end(), 0);	
        int minPassPoints = accumulate(pointsPossible.begin(),
                                       pointsPossible.end(), 0);
        minPassPoints += finalExam;
        minPassPoints = static_cast<int>(ceil(minPassPoints * 0.65));

        int needPoints = minPassPoints - currentPoints;

        if (needPoints <= 0)
        {
            return 0;
        }
        else if (needPoints > finalExam)
        {
            return -1;
        }
        else
        {
            return needPoints;
        }
	}
};

// BEGIN CUT HERE  
int main()  
{  
        PassingGrade ___test;  
        ___test.run_test(-1);  
        return 0;  
}  
// END CUT HERE 
