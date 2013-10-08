#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
    string address_;
    long key_;
    string next_;
};

inline bool compareNode(const Node& a, const Node& b)
{
    return a.key_ < b.key_;
}

int main()
{
    long n = 0;
    string head;
    cin >> n >> head;


    vector<Node> v(n);
    for (long i = 0; i < n; ++i)
    {
        cin >> v[i].address_ >> v[i].key_ >> v[i].next_; 
    }

    // linklist is empty, return 
    if (head == "-1")
    {
        cout << "0 -1" << endl;
        return 0;
    }

    // v2 contains all the valid nodes
    vector<Node> v2;
    while (head != "-1")
    {
        for (long i = 0; i < n; ++i)
        {
            if (v[i].address_ == head)
            {
                v2.push_back(v[i]);
                head = v[i].next_;
            }
        }
    }

    // no valid nodes, return 
    if (v2.size() == 0)
    {
        cout << "0 -1" << endl;
        return 0;
    }

    sort (v2.begin(), v2.end(), compareNode);

    long sz = v2.size();
    cout << sz << " " << v2[0].address_ << endl;
    for (long i = 0; i < sz; ++i)
    {
        if (i != sz -1)
        {
            v2[i].next_ = v2[i+1].address_;
        }
        else
        {
            v2[i].next_ = "-1";
        }

        cout << v2[i].address_ << " " << v2[i].key_ << " " << v2[i].next_ << endl;
    }

    return 0;
}
