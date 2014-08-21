#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdio>
using namespace std;

const int maxK = 10;
const int maxN = 100000+5;
const int NINF = -10000;

struct Stu
{
    int id_;
    int mark_[maxK];
    int total_;
    int nPerfect_;
    int rank_;

    bool operator<(const Stu& other) const
    {
        if (total_ != other.total_)
            return total_ > other.total_;
        else if (nPerfect_ != other.nPerfect_)
            return nPerfect_ > other.nPerfect_;
        else
            return id_ < other.id_;
    }
};

bool badStu(const Stu& x, int k)
{
    for (int j = 1; j <= k; ++j)
    {
        if (x.mark_[j] >= 0)
            return false;
    }
    return true;
}

Stu student[maxN];

int main()
{
    for (int i = 0; i < maxN; ++i)
    {
        student[i].id_ = 0;
        student[i].total_ = NINF;
        student[i].nPerfect_ = 0;
        student[i].rank_ = 0;
        for (int j = 0; j < maxK; ++j)
        {
           student[i].mark_[j] = NINF; 
        }
    }

    freopen("input.txt", "r", stdin);
    int n, k, m;
    scanf("%d%d%d", &n, &k, &m);

    int p[maxK];
    for (int i = 1; i <= k; ++i)
    {
        scanf("%d", &p[i]);
    }

    // read data
    int curID;
    int curPID;
    int curScore;
    for (int i = 0; i < m; ++i)
    {
        scanf("%d %d %d", &curID, &curPID, &curScore);
        student[curID].id_ = curID;
        if (curScore > student[curID].mark_[curPID])
        {
            student[curID].mark_[curPID] = curScore;
        }
        if (curScore == p[curPID])
        {
            student[curID].nPerfect_++;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        if (!badStu(student[i], k))
        {
            student[i].total_ = 0;
            for (int j = 1; j <= k; ++j)
            {
                if (student[i].mark_[j] >= 0)
                {
                    student[i].total_ += student[i].mark_[j];
                }
            }
        }
    }

    sort(student, student + maxN);

    //rank
    for (int i = 0; i < n; ++i)
    {
        student[i].rank_ = i + 1;
        if (i - 1 >= 0 && student[i].total_ == student[i-1].total_)
        {
            student[i].rank_ = student[i-1].rank_;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        printf("%d %05d %d\n", i, student[i].id_, student[i].total_);
    }

    // output
    for (int i = 0; i < n; ++i)
    {
        if (!badStu(student[i], k))
        {
            printf("%d %05d %d", student[i].rank_, student[i].id_, student[i].total_);
            for (int j = 1; j <= k; ++j)
            {
                if (student[i].mark_[j] == NINF)
                    printf(" -");
                else if (student[i].mark_[j] < 0)
                    printf(" 0");
                else
                    printf(" %d", student[i].mark_[j]); 
            }
            printf("\n");
        }
    }

    return 0;
}
