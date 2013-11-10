#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
using namespace std;

class BettingMoney
{
public:

int moneyMade(vector<int> amounts, vector<int> centsPerDollar, int finalResult)
{
    long wins = accumulate(amounts.begin(), amounts.end(), 0L);
    wins = wins - amounts[finalResult];
    wins = 100 * wins;

    long lost = amounts[finalResult] * centsPerDollar[finalResult];

    return wins - lost;
}

};
