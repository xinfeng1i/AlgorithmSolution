#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <utility>
using namespace std;

void QuickSort(vector<int>& v, int left, int right)
{
    // Base Case: if there is <= 1 elements, do nothing
    if (left >= right) return;

    // Partition
    int pivot = v[left];
    int i = left;
    int j = right + 1;
    do{
        do {i++;} while(i <= right && v[i] <= pivot);
        do {j--;} while(j >= left && v[j] > pivot);
        if (i < j) swap(v[i], v[j]);
    }while(i < j);
    swap(v[left], v[j]);

    // recursively quicksort left and right part
    QuickSort(v, left, j - 1);
    QuickSort(v, j + 1, right);
}

void PrintVector(const vector<int>& v)
{
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main()
{
    cout << "Enter the number of elements in your array N:" << endl;
    int n;
    cin >> n;

    cout << "Enter all the elements in your array:" << endl;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    cout << "Before Quick Sort" << endl;
    PrintVector(v);

    QuickSort(v, 0, n - 1);

    cout << "After Quick Sort" << endl;
    PrintVector(v);

    return 0;
}
