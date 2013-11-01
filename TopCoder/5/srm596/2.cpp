#include <iostream>
#include <string>
#include <vector>
using namespace std;

int getMin(string road)
{
    int n = road.size();
    int sum = 0;
    int cur = 0;
    while (cur < n - 1)
    {
        int next = cur + 1;
        if (road[cur] == 'R')
        {
            while (next < n && road[next] != 'G')
            {
                next++;
            }

            if (next == n)
            {
                return -1;
            }

            int next2 = next;
            while (next2 < n && road[next2] == 'G')
            {
                next2++;
            }

            int mid = (next2 + next) / 2;
            next = mid;
            
            sum += (mid - cur) * (mid - cur);
        }
        else if (road[cur] == 'G')
        {
        
            while (next < n && road[next] != 'B')
            {
                next++;
            }

            if (next == n)
            {
                return -1;
            }

            int next2 = next;
            while (next2 < n && road[next2] == 'B')
            {
                next2++;
            }

            int mid = (next2 + next) / 2;
            next = mid;
            
            sum += (mid - cur) * (mid - cur);
        }
        else if (road[cur] == 'B')
        {
            
            while (next < n && road[next] != 'R')
            {
                next++;
            }

            if (next == n)
            {
                return -1;
            }

            int next2 = next;
            while (next2 < n && road[next2] == 'R')
            {
                next2++;
            }

            int mid = (next2 + next) / 2;
            next = mid;
            
            sum += (mid - cur) * (mid - cur);
        }

        cur = next;
        cout << "next pos:"  << next << endl;
    }

    return sum;
}

int main()
{
    string road;
    cin >> road;
    cout << getMin(road) << endl;
    return 0;
}
