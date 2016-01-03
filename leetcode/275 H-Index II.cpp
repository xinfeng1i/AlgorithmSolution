#include <iostream>
#include <string>
#include <vector>
using namespace std;

int hIndex(vector<int>& citations) {
    int n = citations.size();
    int low = 0;
    int high = n - 1;
    
    int mid = -1;
    while (low < high) {
        mid = low + (high - low) / 2;
        if (citations[mid] >= (n - mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    // now we have low >= high
    mid = low + (high - low) / 2;
    if (citations[mid] >= n - mid)
        return n - mid;
    else
        return 0;
    
}

int main()
{
    int a[] = {0, 0};
    vector<int> v(a, a + 2);
    cout << hIndex(v) << endl;
    return 0;
}
