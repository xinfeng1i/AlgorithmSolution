#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    long tmp = 0;
    vector<long> v1;
    vector<long> v2;

    while (true)
    {
        //cin >> tmp;
        scanf("%ld", &tmp);
        if (tmp == -1)
        {
            break;
        }
        v1.push_back(tmp);
    }

    while (true)
    {
        //cin >> tmp;
        scanf("%ld", &tmp);
        if (tmp == -1)
        {
            break;
        }
        v2.push_back(tmp);
    }

    if (v1.size() == 0 && v2.size() == 0)
    {
        cout << "NULL" << endl;
        return 0;
    }

    bool flag = false;
    vector<long>::iterator it1 = v1.begin();
    vector<long>::iterator it2 = v2.begin();
    while (it1 != v1.end() && it2 != v2.end())
    {
        if (*it1 < *it2)
        {
            if (flag)
            {
                //cout << " ";
                printf(" ");
            }
            else
            {
                flag = true;
            }
            printf("%ld", *it1);
            //cout << *it1;
            it1++;
        }
        else
        {
            if (flag)
            {
                cout << " ";
            }
            else
            {
                flag = true;
            }
            //cout << *it2;
            printf("%ld", *it2);
            it2++;
        }
    }
    if (it1 == v1.end())
    {
        while (it2 != v2.end())
        {
            if (flag)
            {
                //cout << " ";
                printf(" ");
            }
            else
            {
                flag = true;
            }
            //cout << *it2;
            printf("%ld", *it2);
            it2++;
        }
    }
    if (it2 == v2.end())
    {
        while (it1 != v1.end())
        {
            if (flag)
            {
                //cout << " ";
                printf(" ");
            }
            else
            {
                flag = true;
            }
            //cout << *it1;
            printf("%ld", *it1);
            it1++;
        }
    }
    //cout << endl;
    printf("\n");
    return 0;
}
