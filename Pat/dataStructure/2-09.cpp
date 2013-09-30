#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    vector<int> stuff(n, 0);
    vector<int> index(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> stuff[i];
    }
    
    vector<int> box(n, 100);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (stuff[i] <= box[j])
            {
                box[j] -= stuff[i];
                index[i] = j + 1;
                break;
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        cout << stuff[i] << " " << index[i] << endl;
    }
    cout << *max_element(index.begin(), index.end()) << endl;
    return 0;

}
