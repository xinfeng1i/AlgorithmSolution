#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

struct Student
{
    long id_;
    char name_[9];
    int grade_;
};

inline bool compareById(const Student& a, const Student& b)
{
    return a.id_ < b.id_;
}

bool compareByName(const Student& a, const Student& b)
{
    if (strcmp(a.name_, b.name_) != 0)
    {
        return strcmp(a.name_, b.name_) < 0;
    }
    else
    {
        return a.id_ < b.id_;
    }
}

bool compareByGrade(const Student& a, const Student& b)
{
    if (a.grade_ != b.grade_)
    {
        return a.grade_ < b.grade_;
    }
    else
    {
        return a.id_ < b.id_;
    }
}

int main()
{
    long n = 0;
    int c = 0;
    scanf("%ld %d", &n, &c);

    vector<Student> v(n);
    for (long i = 0; i < n; ++i)
    {
        scanf("%ld %s %d", &(v[i].id_), v[i].name_, &(v[i].grade_));
    }

    switch (c)
    {
        case 1: sort(v.begin(), v.end(), compareById);
                break;
        case 2: sort(v.begin(), v.end(), compareByName);
                break;
        case 3: sort(v.begin(), v.end(), compareByGrade);
                break;
        default:printf("parameter wrong\n");
                break;
    }
    
    for (long i = 0; i < n; ++i)
    {
        printf("%06ld %s %d\n", v[i].id_, v[i].name_, v[i].grade_);
    }
    return 0;
}
