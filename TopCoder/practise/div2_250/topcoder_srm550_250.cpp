#include <iostream>
#include <string>
using namespace std;

class EasyConversionMachine
{
    public:
        string isItPossible(string originalWord, string finalWord, int k)
        {
            int n = originalWord.size();
            int cnt = 0;
            for (int i = 0; i < n; ++i)
            {
                if (originalWord[i] != finalWord[i]) cnt++;
            }

            if (k>=cnt && (k-cnt) % 2==0) return "POSSIBLE";
            else return "IMPOSSIBLE";
        }
};

