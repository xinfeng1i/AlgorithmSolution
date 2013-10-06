#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

struct Rich
{
    char name_[9];
    int age_;
    long worth_;
};

bool compareRich(const Rich& a, const Rich& b)
{
    if (a.worth_ != b.worth_)
    {
        return a.worth_ > b.worth_;
    }
    else
    {
        if (a.age_ != b.age_)
        {
            return a.age_ < b.age_;
        }
        else
        {
            return strcmp(a.name_, b.name_) < 0;
        }
    }
}

int main()
{
    freopen("1055data.txt", "r", stdin);
    long totalNum = 0;
    int queryNum = 0;
    scanf("%ld %d", &totalNum, &queryNum);
    vector<Rich> richList(totalNum);
    for (long i = 0; i < totalNum; ++i)
    {
        scanf("%s %d %ld", richList[i].name_, &richList[i].age_, &richList[i].worth_);
    }

    sort(richList.begin(), richList.end(), compareRich);

    int outputNum = 0;
    int minAge = 201;
    int maxAge = -1;
    for (int i = 0; i < queryNum; ++i)
    {
        scanf("%d %d %d", &outputNum, &minAge, &maxAge); 
        printf("Case #%d:\n", i+1);
        
        if (minAge > maxAge)
        {
            printf("None\n");
            continue;
        }

        int count = 0;
        for (auto it = richList.begin(); count < outputNum && 
                                         it != richList.end(); ++it)
        {
            if (it->age_ >= minAge && it->age_ <= maxAge)
            {
                printf("%s %d %ld\n", it->name_, it->age_, it->worth_);
                count++; 
            }
        }

        if (count == 0)
        {
            printf("None\n");
        }

    }
        
    return 0;
}
