#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;

int main()
{
//    freopen("Bdata.txt", "r", stdin);
    long n = 0;
    cin >> n;
    vector<string> words(n,"");
    for (long i = 0; i < n; ++i)
    {
        cin >> words[i];
    }

    string pattern("<3");
    bool flag = false;
    for (long i = 0; i < n; ++i)
    {
        pattern += words[i];
        pattern += "<3";
    }

    string message;
    cin >> message;

    long i = 0;
    long j = 0;
    while (i < pattern.size() && j < message.size())
    {
        if (pattern[i] == message[j])
        {
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }

    if (i >= pattern.size() && j >= message.size())
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }
    return 0;
}
