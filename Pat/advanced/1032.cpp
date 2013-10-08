#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

#define smax  100010

struct Node
{
    long address_;
    char data_;
    long next_;
};


int main()
{
    //freopen("1032data.txt", "r", stdin);
    Node a[smax];

    long head1, head2, n;
    cin >> head1 >> head2 >> n;

    long address, next;
    char data;
    for (long i = 0; i < n; ++i)
    {
        scanf("%ld %c %ld", &address, &data, &next);
        a[address].address_ = address;
        a[address].data_ = data;
        a[address].next_ = next;
    }

    vector<Node> word1;
    vector<Node> word2;
    while (head1 != -1)
    {
        word1.push_back(a[head1]);
        head1 = a[head1].next_;
    }

    while (head2 != -1)
    {
        word2.push_back(a[head2]);
        head2 = a[head2].next_;
    }
   
    // if either word is empty, then no common suffix, return -1
    if (word1.size() == 0 || word2.size() == 0)
    {
        cout << -1 << endl;
        return 0;
    }

    auto it1 = word1.rbegin();
    auto it2 = word2.rbegin();
    long suffix_head = -1;
    while (it1 != word1.rend() && it2 != word2.rend() && 
           it1->address_ == it2->address_)
    {
        suffix_head = it1->address_;
        ++it1;
        ++it2;
    }

    // suffix_head hasn't been updated, so no common suffix letter
    if (suffix_head == -1)
    {
        cout << -1 << endl;
    }
    else
    {
        printf("%05ld\n", suffix_head);
    }

    return 0;
}
