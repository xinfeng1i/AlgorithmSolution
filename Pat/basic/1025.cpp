#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <limits>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

struct Node
{
    int address_;
    int data_;
    int next_;
};

int main()
{

    freopen("1025data.txt", "r", stdin); 
    Node a[100000];

    int startAddress, n, k;
    scanf("%d %d %d", &startAddress, &n, &k);

    // init
    int address, data, next;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d %d %d", &address, &data, &next);
        a[address].address_ = address;
        a[address].data_ = data;
        a[address].next_ = next;
    }


    // empty link list
    if (startAddress == -1)
    {
        printf("-1\n");
        return 0;
    }

    vector<Node> v;
    v.reserve(n);
    while (startAddress != -1)
    {
        v.push_back(a[startAddress]);
        startAddress = a[startAddress].next_;
    }

    // the vector contain all the valid nodes, so the valid node
    // may not equal to the original n, so set the n to the v.size();
    // BE CAREFUL
    n = v.size();

    int iterTimes = n / k;
    for (int i = 0; i < iterTimes; ++i)
    {
        for (int s = k * i, e = k * (i + 1) - 1; s <= e; ++s, --e)
        {
            swap(v[s], v[e]);
        }
    }

    for (int i = 0; i < n - 1; ++i)
    {
        printf("%05d %d %05d\n", v[i].address_, v[i].data_, v[i+1].address_);
    }
    printf("%05d %d -1\n", v[n-1].address_, v[n-1].data_);
    return 0;
}
