#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

struct Man
{
    long id_;
    int virtue_;
    int talent_;
    int degree_;
};

int getDegree(int virtue, int talent, int h)
{
    if (virtue >= h && talent >=h)
    {
        return 1;
    }
    else if (virtue >= h && talent < h)
    {
        return 2;
    }
    else if (virtue < h && talent < h && virtue >= talent)
    {
        return 3;
    }
    else
    {
        return 4;
    }
}

bool compareMan(const Man& a, const Man& b)
{
    if (a.degree_ != b.degree_)
    {
        return a.degree_ < b.degree_;
    }
    else
    {
        if (a.virtue_ + a.talent_ != b.virtue_ + b.talent_)
        {
            return a.virtue_ + a.talent_ > b.virtue_ + b.talent_;
        }
        else
        {
            if (a.virtue_ != b.virtue_)
            {
                return a.virtue_ > b.virtue_;
            }
            else
            {
                return a.id_ < b.id_;
            }
        }
    }

}

int main()
{
    //freopen("1015data.txt", "r", stdin);

    long n;
    int low, high;
    scanf("%ld %d %d", &n, &low, &high);

    vector<Man> v;
    v.reserve(100000);
    Man man;
    for (long i = 0; i < n; ++i)
    {
        scanf("%ld %d %d", &man.id_, &man.virtue_, &man.talent_);
        if (man.virtue_ >= low && man.talent_ >= low)
        {
            man.degree_ = getDegree(man.virtue_, man.talent_, high);
            v.push_back(man);
        }
    }

    sort(v.begin(), v.end(), compareMan);

    long sz = v.size();
    printf("%ld\n", sz);
    for (long i = 0; i < sz; ++i)
    {
        printf("%08ld %d %d\n", v[i].id_, v[i].virtue_, v[i].talent_);
    }
    return 0;
}
