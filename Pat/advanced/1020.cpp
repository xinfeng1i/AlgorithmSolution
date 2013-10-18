#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define N 35


int post_order[N];
int in_order[N];
int visited[N];
queue<int> q;

int getPosInPost(int elem, int n)
{
    for (int i = 0; i < n; ++i)
    {
        if (elem == post_order[i])
        {
            return i;
        }
    }
}

// push left and right child of root into queue
void createdTree(int root, int n)
{
    // find root in the in_order array
    int i = 0;
    for (i = 0; i < n; ++i)
    {
        if (in_order[i] == root)
        {
            break;
        }
    }

    // label this position as visited
    visited[i] = 1;
    int left_most = i - 1;
    int right_most = i + 1;

    // find the left tree elements range
    while (left_most >= 0 && !visited[left_most])
    {
        left_most--;
    }
    left_most++;

    // find the right tree elements range
    while (right_most < n && !visited[right_most])
    {
        right_most++;
    }
    right_most--;

    // both left and right tree has no elems, return
    if (i - left_most == 0 && right_most - i == 0)
    {
        return;
    }

    // find the left root of the left subtree
    int left_root = in_order[left_most];
    int left_max_pos = getPosInPost(left_root, n);
    for (int k = left_most; k < i; ++k)
    {
        int tmp_pos = getPosInPost(in_order[k], n); 
        if (tmp_pos > left_max_pos)
        {
            left_root = in_order[k];
        }
    }

    if (left_root != root)
    {
        q.push(left_root);
    }

    // find the root the right subtree
    int right_root = in_order[right_most];
    int max_right_pos = getPosInPost(right_root, n);
    for (int k = right_most; k > i; --k)
    {
        int tmp_pos = getPosInPost(in_order[k], n);
        if (tmp_pos > max_right_pos)
        {
            right_root = in_order[k];
        }
    }

    if (right_root != root)
    {
        q.push(right_root);
    }

    if (left_root != root)
    {
        createdTree(left_root, n);
    }
    if (right_root != root)
    {
        createdTree(right_root, n);
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> post_order[i];
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> in_order[i];
    }

    for (int i = 0; i < n; ++i)
    {
        visited[i] = 0;
    }
   
    q.push(post_order[n-1]);
    createdTree(post_order[n-1], n);

    bool flag = false;
    while (!q.empty())
    {
        if (flag)
        {
            cout << " ";
        }
        else
        {
            flag = true;
        }
        cout << q.front();

        q.pop();
    }
    cout << endl;
    
}
