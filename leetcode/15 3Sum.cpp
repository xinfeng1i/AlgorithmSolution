#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// two pointer to find the target (-a)
// time complexity O(n^2)
vector<vector<int> > threeSum(vector<int>& nums) {
    vector<vector<int> > result;
    vector<int> temp;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int i = 0;
    int j, k;
    while (i < n - 2) {
        int a = nums[i];
        j = i + 1;
        k = n - 1;
        
        while (j < k) {
            int b = nums[j];
            int c = nums[k];
            if (b + c == -a) {
                temp.clear();
                temp.push_back(a);
                temp.push_back(b);
                temp.push_back(c);
                result.push_back(temp);
                
                // find the next different number2
                int nextJ = j + 1;
                while (nextJ < k && nums[nextJ] == nums[j]) nextJ++;
                if (nextJ >= k) break;
                j = nextJ;
                
                // find the next different number3
                int nextK = k - 1;
                while (nextK > j && nums[k] == nums[nextK]) nextK--;
                if (nextK <= j) break;
                k = nextK;
            } else if (b + c > -a) {
                k--;
            } else {
                j++;
            }
        }
        
		// find the next different number1
        int nextI = i + 1;
        while (nextI < n && nums[nextI] == nums[i]) nextI++;
        i = nextI;
    }
    return result;
}

void PrintVec(const vector<int>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        cout << " " << v[i];
    }
    cout << endl;
}

int main()
{
    int a[] = {-1, 0, 1, 2, -1, 4};
    vector<int> nums(a, a + 6);
    vector<vector<int> > result;
    result = threeSum(nums);
    
    for (size_t i = 0; i < result.size(); ++i) {
        PrintVec(result[i]);
    }
    return 0;
}
