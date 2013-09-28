#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool modifyString(string& s)
{
    bool flag = false;
    for (int i = 0; i < s.size(); ++i)
    {
        switch(s[i])
        {
            case '1': s[i] = '@';
                       flag = true;
                       break;
            case '0': s[i] = '%';
                       flag = true;
                       break;
            case 'l': s[i] = 'L';
                       flag = true;
                       break;
            case 'O': s[i] = 'o';
                       flag = true;
                       break;
        }
    }

    return flag == true;
}

int main()
{
    int N = 0;
    cin >> N;

    vector<pair<string, string> > v;
    string name, password;
    for (int i = 0; i < N; ++i)
    {
        cin >> name >> password;
        if (modifyString(password))
        {
            v.push_back(pair<string,string>(name, password));
        }
    }

    if (N == 1)
    {
        cout << "There is 1 account and no account is modified" << endl;
        return 0;
    }

    int M = v.size();
    if (M == 0)
    {
        cout << "There are " << N << " accounts and no account is modified" << endl;
        return 0;
    }

    cout << M << endl;
    for (int i = 0; i < M; ++i)
    {
        cout << v[i].first << " " << v[i].second << endl;
    }

    return 0;
}
