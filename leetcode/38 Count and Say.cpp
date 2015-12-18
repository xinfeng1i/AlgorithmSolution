#include <iostream>
#include <string>
using namespace std;

string countAndSay(int n)
{
    int idx = 1;
    string cur = "1";
    while (idx < n) {
        string next = "";
        int i = 0;
        int cnt = 1;
        int j = i + 1;
        int n = cur.size();
        while (i < n) {
            j = i + 1;
            while (j < n && cur[j] == cur[i]) j++;
            cnt = j - i;
            next += '0' + cnt;
            next += cur[i];
            i = j;
        }
        cur = next;
        idx++;
    }
    return cur;
}

int main()
{
    cout << countAndSay(5) << endl;
    return 0;
}
