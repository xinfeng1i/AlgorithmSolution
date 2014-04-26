#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <numeric>
#include <limits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cassert>
using namespace std;

typedef long long ll;
struct Student
{
    ll id;
    int grade;
    int finalRank;
    int placeID;
    int localRank;
};

bool cmpStudent(const Student& s1, const Student& s2)
{
    if (s1.grade != s2.grade)
    {
        return s1.grade > s2.grade;
    }
    else
    {
        return s1.id < s2.id;
    }
}

// 坑点：如果使用long long作为学号，如果学号以000开始，需要在printf时候前面补0
int main()
{
    freopen("pat_data-structure_707_data.txt", "r", stdin);
    int n = 0, k = 0;
    scanf("%d", &n);
    vector<vector<Student> > v(n);

    vector<int> wholeGrades;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &k);

        vector<int> localGrades(k);
        v[i].resize(k);
        for (int j = 0; j < k; ++j)
        {
            scanf("%lld %d", &v[i][j].id, &v[i][j].grade);
            v[i][j].placeID = i + 1;
            localGrades[j] = v[i][j].grade;
            wholeGrades.push_back(v[i][j].grade);
        }

        sort(v[i].begin(), v[i].end(), cmpStudent);
        sort(localGrades.begin(), localGrades.end(), greater<int>());

        for (int j = 0; j < k; ++j)
        {
            v[i][j].localRank = lower_bound(localGrades.begin(), localGrades.end(), v[i][j].grade, greater<int>()) - localGrades.begin() + 1;
        }
    }

    vector<Student> ans;
    for (int i = 0; i < n; ++i)
    {
        vector<Student> tmp(ans.begin(), ans.end());
        ans.resize(tmp.size() + v[i].size());
        merge(tmp.begin(), tmp.end(), v[i].begin(), v[i].end(), ans.begin(), cmpStudent);
    }

    sort(wholeGrades.begin(), wholeGrades.end(), greater<int>());
    for (int i = 0; i < ans.size(); ++i)
    {
        ans[i].finalRank = lower_bound(wholeGrades.begin(), wholeGrades.end(), ans[i].grade, greater<int>()) - wholeGrades.begin() + 1;
    }

    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i)
    {
        printf("%013lld %d %d %d\n", ans[i].id, ans[i].finalRank, ans[i].placeID, ans[i].localRank);
    }
    return 0;
}