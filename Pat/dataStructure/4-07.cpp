#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
using namespace std;

/* 霍夫曼树问题，需要使用小根堆数据结构
 * 优先级队列默认是大根堆，通过改变比较运算符greater<int>变为
 * 小根堆使用
 *  
 *  记住priority_queue的模版参数需要指定
 *  priority_queue<int, vector<int>, greater<int> > q;
 */
int main()
{
    priority_queue<int, vector<int>, greater<int> > q;
    int n;
    scanf("%d", &n);

    int x;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &x);
        q.push(x);
    }

    int cost = 0;
    int x1, x2;
    while (q.size() >= 2)
    {
        x1 = q.top();
        q.pop();
        x2 = q.top();
        q.pop();
        cost += x1 + x2;
        q.push(x1 + x2);
    }

    cout << cost << endl;
    return 0;
}
