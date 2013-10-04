#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

struct NumPos
{
    long num;
    long pos;
};

bool myCmp(const NumPos& a, const NumPos& b)
{
    if (a.num < b.num)
    {
        return true;
    }
    else if (a.num == b.num)
    {
        return a.pos < b.pos;
    }
    else
    {
        return false;
    }
}

long diffArray(vector<NumPos>::iterator it1, vector<NumPos>::iterator it2)
{
    if (it2 - it1 == 1)
    {
        return 0;
    }
    if (it2 - it1 == 2)
    {
        return (it1+1)->pos - it1->pos;
    }

    vector<long> array;
    while (it1 != it2)
    {
        array.push_back(it1->pos);
        it1++;
    }

    bool flag = true;
    long d = array[1] - array[0];
    for (long i = 1; i < array.size(); ++i)
    {
        if (array[i] != array[0] + i * d)
        {
            flag = false; 
        }
    }
    
    if (!flag)
    {
        return -1;
    }
    else
    {
        return d;
    }
}
int main()
{
    long n = 0;
    cin >> n;
    vector<NumPos> numbers(n);
    long tmp = 0;
    for (long i = 0; i < n; ++i)
    {
        cin >> tmp;
        numbers[i].num = tmp;
        numbers[i].pos = i + 1;
    }

    sort(numbers.begin(), numbers.end(), myCmp);
    map<long, long> ans;

    vector<NumPos>::iterator cur = numbers.begin();
    vector<NumPos>::iterator tmp_next;
    while (cur != numbers.end())
    {
        tmp_next = cur + 1;
        while (tmp_next != numbers.end() && tmp_next->num == cur->num)
        {
            tmp_next++;
        }
        long dd = diffArray(cur, tmp_next);
        if (dd != -1)
        {
            ans.insert(pair<long, long>(cur->num, dd));
        }

        cur = tmp_next;
    }


    cout << ans.size() << endl;
    for (map<long, long>::iterator it = ans.begin(); it != ans.end(); ++it)
    {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}
