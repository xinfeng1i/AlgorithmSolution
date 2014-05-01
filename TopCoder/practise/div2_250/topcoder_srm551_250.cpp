#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
using namespace std;

// AC code: 229pts
class ColorfulBricks
{
    public:
        int countLayouts(string bricks)
        {
            sort(bricks.begin(), bricks.end());
            set<string> s;
            do
            {
                int cnt = 0;
                for (int i = 1; i < bricks.size(); ++i)
                {
                    if (bricks[i] != bricks[i-1]) cnt++;
                }
                if (cnt <= 1) 
                {
                    s.insert(bricks);
                }
            }while(next_permutation(bricks.begin(), bricks.end()));

            return s.size();
        }
};
