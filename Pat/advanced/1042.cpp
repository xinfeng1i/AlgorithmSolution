#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void myShuffle(vector<string>& v, const vector<int>& order)
{
    vector<string> v2(v.begin(), v.end());
    for (int i = 0; i < order.size(); ++i)
    {
        int j = order[i]; 
        v2[j] = v[i];
    }
    copy(v2.begin(), v2.end(), v.begin());
}

int main()
{
    //freopen("1042data.txt", "r", stdin);

    // init cards
    vector<string> cards(54 + 1);
    for (int i = 1; i <= 13; ++i)
    {
        cards[i] = "S" + to_string(i);
    }
    for (int i = 1; i <= 13; ++i)
    {
        cards[i + 13] = "H" + to_string(i);
    }
    for (int i = 1; i <= 13; ++i)
    {
        cards[i + 26] = "C" + to_string(i);
    }
    for (int i = 1; i <= 13; ++i)
    {
        cards[i + 39] = "D" + to_string(i);
    }
    cards[53] = "J1";
    cards[54] = "J2";
    // end of initing cards

    int k = 0;
    cin >> k;
    vector<int> givenOrder(54+1);
    for (int i = 1; i <= 54; ++i)
    {
        cin >> givenOrder[i];
    }

    // core algorihm: shuffle
    for (int i = 0; i < k; ++i)
    {
        myShuffle(cards, givenOrder);
    }

    // output
    cout << cards[1];
    for (int i = 2; i <= 54; ++i)
    {
        cout << " " << cards[i];
    }
    cout << endl;
    return 0;

}
