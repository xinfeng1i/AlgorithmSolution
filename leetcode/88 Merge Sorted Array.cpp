#include "MyHeader.h";

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    int cnt1 = 0;
    int cnt2 = 0;
    int i = 0;
    int j = 0;
    while (cnt1 < m && cnt2 < n)
    {
        if (nums1[i] <= nums2[j])
        {
            i++;
            cnt1++;
        }
        else
        {
            int sz = m + cnt2;
            for (int k = sz; k >= i + 1; --k)
            {
                nums1[k] = nums1[k-1];
            }
            nums1[i] = nums2[j];
            i++;
            j++;
            cnt2++;
        }
    }

    if (cnt2 < n)
    {
        int cur = cnt1 + cnt2;
        for (int k = j; k < n; ++k)
        {
            nums1[cur] = nums2[k];
            cur++;
        }
    }
}