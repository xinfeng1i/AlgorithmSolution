#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct SLinkNode
{
    int curAddr_;       // current node address
    int data_;          // current node data field
    int nextAddr_;      // next node address

    SLinkNode():curAddr_(-1),data_(0),nextAddr_(-1)
    {}
};

const int MAX_N = 100000 + 5;
SLinkNode a[MAX_N];

int main()
{
    //freopen("input.txt", "r", stdin);
    int startAddr = -1; 
    int n = 0; 
    int k = 0;

    // read the input
    cin >> startAddr >> n >> k;
    SLinkNode tmp;
    for (int i = 0; i < n; ++i)
    {
        cin >> tmp.curAddr_ >> tmp.data_ >> tmp.nextAddr_; 
        a[tmp.curAddr_] = tmp;
    }
    
    // construct the single link list
    vector<SLinkNode> v;
    v.reserve(n);
    int myAddr = startAddr;
    while (myAddr != -1)
    {
        v.push_back(a[myAddr]);
        myAddr = a[myAddr].nextAddr_;
    }

    // reverse the link list every k nodes
    int vFloorSize = int(v.size() - (v.size() % k));
    for (size_t i = 0; i < vFloorSize; i += k)
    {
        reverse(v.begin() + i, v.begin() + i + k);
    }

    for (size_t i = 0; i + 1 < v.size(); ++i)
    {
        v[i].nextAddr_ = v[i+1].curAddr_;
    }
    int lastIndex = int(v.size()) - 1;
    v[lastIndex].nextAddr_ = -1;

    // output
    for (size_t i = 0; i + 1 < v.size(); ++i)
    {
        printf("%05d %d %05d\n", v[i].curAddr_, v[i].data_, v[i].nextAddr_);
    }
    printf("%05d %d -1\n", v[lastIndex].curAddr_, v[lastIndex].data_);
    return 0;
}

