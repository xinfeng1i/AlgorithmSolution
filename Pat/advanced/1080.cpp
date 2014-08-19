#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

struct Stu
{
    int id_;
    int ge_;
    int gi_;
    double average_;
    int rank_;
    vector<int> school_;

    bool operator< (const Stu& other) const
    {
        if (average_ != other.average_)
            return average_ > other.average_;
        else
            return ge_ > other.ge_;
    }
};

int main()
{
    freopen("input.txt", "r", stdin);
    int n = 0;
    int m = 0;
    int k = 0;
    scanf("%d %d %d", &n, &m, &k);

    vector<int> quota(m, 0);
    for (int i = 0; i < m; ++i) scanf("%d", &quota[i]);

    // read data
    vector<Stu> student(n);
    int sch;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d %d", &student[i].ge_, &student[i].gi_); 
        student[i].average_ = (student[i].ge_ + student[i].gi_) / 2.0;
        student[i].id_ = i;
        for (int j = 0; j < k; ++j)
        {
            scanf("%d", &sch);
            student[i].school_.push_back(sch);
        }
    }

    // sort
    sort(student.begin(), student.end());
    for(int i = 0; i < n; ++i)
    {
        student[i].rank_ = i;
        if (i - 1 >= 0 && student[i].ge_ == student[i-1].ge_
                       && student[i].gi_ == student[i-1].gi_)
        {
            student[i].rank_ = student[i-1].rank_;
        }
    }
    
    // admission
    vector<vector<int> > school(m);
    /* Remember the last rank and school of the last admissed student
     * It will help decide if the quota has exceeded, whether or not 
     * to continue admission
     */
    int lastAdmissionRank = 0;
    int lastAdmissionSchool = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < student[i].school_.size(); ++j)
        {
            int choice = student[i].school_[j];
            if (quota[choice] > 0)
            {
                school[choice].push_back(student[i].id_);
                quota[choice]--;
                lastAdmissionRank = student[i].rank_;
                lastAdmissionSchool = choice;
                break;
            }
            else
            {
                if (student[i].rank_ == lastAdmissionRank &&
                    student[i].school_[j] == lastAdmissionSchool)
                {
                    school[choice].push_back(student[i].id_);
                    quota[choice]--;
                    lastAdmissionRank = student[i].rank_;
                    lastAdmissionSchool = choice;
                    break;
                }
            }
        }
    }


    // output
    for (int i = 0; i < m; ++i)
    {
        sort(school[i].begin(), school[i].end());
        for (int j = 0; j < school[i].size(); ++j)
        {
            if (j != 0) printf(" ");
            printf("%d", school[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
