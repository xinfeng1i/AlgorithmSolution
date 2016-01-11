#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int trapRecursive(vector<int>& height, int low, int high);

int trap(vector<int>& height) {
    int n = height.size();
    return trapRecursive(height, 0, n-1);
}

int trapRecursive(vector<int>& height, int low, int high) {
    if (high-low+1<=2) return 0;
    
    // find the two tallest bar in [low, high] 
    vector<int> temp(height.begin()+low, height.begin()+high+1);
    sort(temp.begin(), temp.end(), greater<int>());
    int h1 = temp[0];
    int h2 = temp[1];
    // find their index of the two tallest bar
    int i = low; int j = high;
    for (i = low; i <= high; ++i) {
        if (height[i] == h1 || height[i] == h2)
            break;
    }
    for (j = i + 1; j <= high; ++j) {
        if (height[j] == h1 || height[j] == h2)
            break;
    }
    
    // calculate the area between these two tallest bar
    int water = (j - i - 1) * min(h1, h2);
    // minus that bars between them
    for (int k = i + 1; k <= j - 1; ++k) {
        water -= height[k];
    }
    
    // recursively calclulate the left part and right bar beyond [i,j]
    int waterLeft = trapRecursive(height, low, i);
    int waterRight = trapRecursive(height, j, high);
    return water + waterLeft + waterRight;
}

int main()
{
    int a[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    vector<int> height(a, a + 12);
    cout << trap(height) << endl;
    return 0;
}
