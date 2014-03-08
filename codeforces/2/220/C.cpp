#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<string> a;

int dima()
{
    bool found = false;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (a[i][j] == 'D')
            {
                found = true;
                break;
            }
        }
    }

    if (!found)
    {
        return -1;
    }


}

void flood(int i, int j)
{
}


int main()
{
    cin >> n >> m;
    a.resize(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    vector<vector<int> > flag(n, vector<int>(m, 0));


    return 0;
}

