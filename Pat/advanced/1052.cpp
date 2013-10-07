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

    sort (v.begin(), v.end(), compareNode);

    cout << n << " " << v[0].address_ << endl;
    for (long i = 0; i < n; ++i)
    {
        if (i != n -1)
        {
            v[i].next_ = v[i+1].address_;
        }
        else
        {
            v[i].next_ = "-1";
        }

        cout << v[i].address_ << " " << v[i].key_ << " " << v[i].next_ << endl;
    }

    return 0;
}
