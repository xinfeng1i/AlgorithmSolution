#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
    //freopen("1039data.txt", "r", stdin);

    long queryNumber = 0;
    int courseNumber = 0;
    cin >> queryNumber >> courseNumber;

    map<string, set<int> > table;
    int courseIndex = 0;
    long studentNumber = 0;
    string name;
    for (int i = 0; i < courseNumber; ++i)
    {
        cin >> courseIndex >> studentNumber;
        for (int k = 0; k < studentNumber; ++k)
        {
            cin >> name;
            table[name].insert(courseIndex);
        }
    }

    vector<string> querylist(queryNumber);
    string queryName;
    for (long i = 0; i < queryNumber; ++i)
    {
        cin >> queryName;
        int registerNumber = table[queryName].size();
        cout << queryName << " " << registerNumber;
        if (registerNumber == 0)
        {
            //cout << endl;
            printf("\n");
        }
        else
        {
            for (auto it = table[queryName].begin(); 
                      it != table[queryName].end(); ++it)
            {
                //cout << " " << *it;
                printf(" %d", *it);
            }
            //cout << endl;
            printf("\n");
        }
    }

    return 0;
}
