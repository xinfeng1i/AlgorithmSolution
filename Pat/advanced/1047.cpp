#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

struct Stu
{
    char name[5];
    long id;
};

bool compareStu(const Stu& a, const Stu& b)
{
    return strcmp(a.name, b.name) < 0;
}

Stu studentList[40005];
bool mark[40005] = {0};
vector<int> courseList[2505];

int main()
{
    //freopen("1047data.txt", "r", stdin);
    long studentNum;
    int courseNum;
    scanf("%ld %d", &studentNum, &courseNum);
    int tmp_k, tmp_course;
    for (long i = 0; i < studentNum; ++i)
    {
        scanf("%s %d", studentList[i].name, &tmp_k);
        studentList[i].id = i; 
        for (int j = 0; j < tmp_k; ++j)
        {
            scanf("%d", &tmp_course);
            courseList[tmp_course].push_back(i);
        }
    }

    sort(studentList, studentList + studentNum, compareStu);

    for (int i = 1; i <= courseNum; ++i)
    {
        printf("%d %d\n", i, courseList[i].size());
        for (int j = 0; j < courseList[i].size(); ++j)
        {
            mark[courseList[i][j]] = 1;
        }

        for (long k = 0; k < studentNum; ++k)
        {
            if (mark[studentList[k].id])
            {
                printf("%s\n", studentList[k].name);
            }
        }

        for (int j = 0; j < courseList[i].size(); ++j)
        {
            mark[courseList[i][j]] = 0;
        }

    }

    return 0;
}

// Summay:
// 1. if use C++ the best data structure is use map<int, set<int> > courseList, it
//    can get the result directly, but it cost too much memory and time.
// 2. The best way is bind every student name a id number, the easiest way is
//    binding every name a number 0...N-1, then we use courseList with id
//    numbers, but this cause a problem, the name must print in acceding order
//    so we can sort the studentList, but this will disorder the id numbers. so
//    we have to use a bool array to mark the id numbers occurred in the
//    courseList. then search the studentList
//    Time Complexity is: O(NlogN) + O(courseNum * studentNum)
// 3. This problem involves large number of I/O, so use scanf/printf will save
//    a lot fo I/O time. But scanf/printf cannot handle C++ style string, I
//    have to change all the string to char array like name[5], what a shame!
//
// Created by python27
// 2013/10/06
