#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>
using namespace std;


int main()
{

    long count[100005] = {0};
    long n = 0;
    cin >> n;
    vector<int> flag(n + 1, 0);
    flag[0] = -1;
    for (long i = 1; i < n + 1; ++i)
    {
        cin >> flag[i];
    }

    vector<int> a(n + 1, 0);
    a[0] = -1;
    for (long i = 1; i < n + 1; ++i)
    {
        cin >> a[i];
        long temp = a[i];
        count[temp]++;
        if (count[temp] > 1)
        {
            flag[temp] = -1;
        }
    }

    long max_length = 0;
    long max_place = -1;
    for (long i = 1; i < n + 1; ++i)
    {
        if (flag[i] == 1)
        {
            int place = i; 
            int cnt_place = 1;
            while (flag[a[place]] == 0)
            {
                place = a[place];
                cnt_place++;
            }
            if (cnt_place > max_length)
            {
                max_place = i; 
                max_length = cnt_place;
            }
        }
    }

    cout << max_length << endl;
    stack<long> s;
    s.push(max_place);
    long tmp;
    while (flag[a[max_place]] == 0)
    {
        s.push(a[max_place]); 
        max_place = a[max_place];
    }

    bool printflag = false;
    while (!s.empty())
    {
        if (printflag)
        {
            cout << " ";
        }
        else
        {
            printflag = true;
        }
        cout << s.top();
        s.pop();
    }
    cout << endl;
    return 0;

}
