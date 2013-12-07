#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 * Because the lower bound of the item is 101 and the
 * bin capacity is 300, so every bin can contain 2 items
 * at more. 
 *
 * So we can find all the pairs that can be put in one bin,
 * then the bin cnt minus one from the total cnt
 * 
 * From: editorial
 */
int minBins(vector<int> item)
{
    sort(item.begin(), item.end());
    int binCnt = item.size();
    int n = item.size();

    int i = 0;
    int j = n - 1;

    // find the suitale couples if possible
    while (i < j)
    {
        // find the from the end to begin
        while (j > i && item[j] + item[i] > 300)
        {
            --j;
        }

        // if find the possible item, the bin cnt - 1
        if (i < j && item[i] + item[j] <= 300)
        {
            binCnt--;
            i++;
            j--;
        }
        // if cannot find, then return
        else
        {
            break;
        }
    }

    return binCnt;
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

    cout << minBins(v) << endl;

    return 0;
}
