#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

const int nMax = 12;

struct Stu
{
    char name_[nMax];
    char ID_[nMax];
    int grade_;
public:
    bool operator< (const Stu& other) const
    {
        return grade_ > other.grade_; 
    }
};

int main()
{
    freopen("input.txt", "r", stdin);
    int n = 0;
    scanf("%d", &n);
    vector<Stu> student(n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%s %s %d", &student[i].name_, 
                          &student[i].ID_, 
                          &student[i].grade_);
    }

    int x = 0, y = 0;
    scanf("%d %d", &x, &y);

    sort(student.begin(), student.end());

    bool flag = false;
    for (int i = 0; i < n; ++i)
    {
        if (student[i].grade_ >= x && student[i].grade_ <= y)
        {
            printf("%s %s\n", student[i].name_, student[i].ID_);
            flag = true;
        }
    }
    if (!flag) printf("NONE\n");

    /*
    int lower = n;
    int upper = -1000;
    for (int i = n-1; i >= 0; --i)
    {
        if (student[i].grade_ >= x)
        {
            upper = i;
            break;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        if (student[i].grade_ <= y);
        {
            lower = i;
            break;
        }
    }

    // output
    if (x > y || lower > upper)
    {
        printf("NONE\n");
    }
    else
    {
        for (int i = lower; i <= upper; ++i)
        {
            printf("%s %s\n", student[i].name_,
                               student[i].ID_);
        }
    }
    */
    return 0;
}
