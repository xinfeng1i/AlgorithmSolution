#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class NumArray {
public:
    NumArray(vector<int> &nums) {
        sumNums.resize(nums.size());
        partial_sum(nums.begin(), nums.end(), sumNums.begin()); 
    }

    int sumRange(int i, int j) {
        if (i == 0) return sumNums[j];
        else return (sumNums[j] - sumNums[i-1]);
    }
private:
    vector<int> sumNums;
};


int main()
{
    int a[6] = {-2, 0, 3, -5, 2, -1};
    vector<int> v(a, a+6);
    NumArray test(v);
    cout << test.sumRange(0, 2) << endl;
    cout << test.sumRange(2, 5) << endl;
    cout << test.sumRange(0, 5) << endl;
    return 0;
}
