#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int hIndex(vector<int>& citations) {
    sort(citations.begin(), citations.end(), greater<int>());
    int n = citations.size();
    int i = 0;
    while (i < n && citations[i] >= (i + 1)) i++;
    return i;
}

int main()
{
    int a[] = {3, 0, 6, 1, 5};
    vector<int> v(a, a + 5);
    cout << hIndex(v) << endl;
    return 0;
}
