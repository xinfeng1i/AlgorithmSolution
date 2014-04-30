#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
using namespace std;

// Ac code: 172pts
// brute force
class TheJediTestDiv2
{
    public:
        int countSupervisors(vector<int> student, int Y, int J)
        {
            int ans = 1000000;
            int n = student.size();
            for (int k = 0; k < n; ++k)
            {
                int cnt = 0;
                for (int i = 0; i < n; ++i)
                {
                    if (i != k)
                        cnt += (int)ceil(student[i] / (J + 0.0f));
                }

                if (student[k] > Y)
                  cnt += (int)ceil((student[k] - Y) / (J + 0.0));

                ans = min(ans, cnt);
           }

           return ans;
        }
};
