#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

/* 
 * 数据压缩, 排序，二分搜索：
 * 由于每个学生name是有3个大写字母和1个数字组成的，可以当成26进制数压缩
 * 成一个整数sid, 而每个课程的编号cid取值范围在[1,2500]之间，对于任意一条
 * 记录：某学生选择了某课程可以用一个整数gid = sid * 2500 + cid - 1唯一
 * 表示；当给定一个gid时，可以通过gid % 2500 + 1来得到对应的课程标号。
 * 现在当需要查询一个学生的选课记录时，首先计算学生的sid，则其可能的选课
 * 记录必然保存在整数 [sid*2500, sid*2500+2499]，我们对上下界进行二分搜索
 * 即可得到对应的gid，进而得到课程标号.
 * 
 * 参考：tech-wonderland.net/blog/pat-1039-course-list-for-student.html
 */

const int pow0 = 1;
const int pow1 = 26;
const int pow2 = 676;
const int pow3 = 17576;

int binarySearch(const vector<int>& gids, int gid)
{
    int n = gids.size();
    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (gids[mid] == gid)
        {
            return mid;
        }
        else if (gid < gids[mid])
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int queryNum = 0;
    int courseNum = 0;
    char stuName[5];
    scanf("%d %d", &queryNum, &courseNum);

    vector<int> gids;
    gids.reserve(courseNum * 200);
    int courseID = 0; int stuCnt = 0;
    for (int k = 0; k < courseNum; ++k)
    {
        scanf("%d %d", &courseID, &stuCnt);
        for (int i = 0; i < stuCnt; ++i)
        {
            scanf("%s", stuName);
            int sid = (stuName[0] - 'A') * pow3 + 
                      (stuName[1] - 'A') * pow2 + 
                      (stuName[2] - 'A') * pow1 + 
                      (stuName[3] - '0');
            int gid = sid * 2500 + courseID - 1;
            gids.push_back(gid);
        }
    }

    sort(gids.begin(), gids.end());

    for (int k = 0; k < queryNum; ++k)
    {
        scanf("%s", stuName);
        int queryid = (stuName[0] - 'A') * pow3 + 
                      (stuName[1] - 'A') * pow2 + 
                      (stuName[2] - 'A') * pow1 + 
                      (stuName[3] - '0');
        int lowid = queryid * 2500 + 0;
        int highid = queryid * 2500 + 2499;
        int i = binarySearch(gids, lowid);
        int j = binarySearch(gids, highid);
        vector<int> ans;
        for (int kk = i; kk <= j; ++kk)
        {
            if (gids[kk] >= lowid && gids[kk] <= highid)
            {
                ans.push_back(gids[kk]);
            }
        }
        printf("%s", stuName);
        int ansNum = ans.size();
        printf(" %d", ansNum);
        for (size_t ii = 0; ii < ans.size(); ++ii)
        {
            int gid = ans[ii];
            int cid = gid % 2500 + 1;
            printf(" %d", cid);
        }
        printf("\n");
    }
    return 0;
}
