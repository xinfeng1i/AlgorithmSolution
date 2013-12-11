#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int maxTurns(vector<int> cards)
{
    sort(cards.begin(), cards.end());
    
    int cnt = 0;
    for (int i = 0; i < cards.size(); )
    {
        if (cards[i] + 1 == cards[i + 1])
        {
            i += 2;
            cnt++;
            //cout << "remove " << i << " and " << i + 1 << endl;
        }
        else
        {
            i++;
            cnt++;
            //cout << "remove: " << i << endl;
        }
    }

    return cnt;
}

int main()
{
    int n;
    cin >> n;
    
    vector<int> v(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    cout << maxTurns(v) << endl;
    return 0;
}
