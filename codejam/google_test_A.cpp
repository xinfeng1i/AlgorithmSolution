#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
using namespace std;

vector<int> divideNumbers(const string& format);
void readString(string s);

ofstream fout("A.out", ios::out);

string spellNumber(int n)
{
    switch(n)
    {
        case 0: return "zero";
                break;
        case 1: return "one";
                break;
        case 2: return "two";
                break;
        case 3: return "three";
                break;
        case 4: return "four";
                break;
        case 5: return "five";
                break;
        case 6: return "six";
                break;
        case 7: return "seven";
                break;
        case 8: return "eight";
                break;
        case 9: return "nine";
                break;
        default: return "error";
                break;
    }
}

// format no more than 10
void readPhoneNumber(string pNumber, string format)
{
    vector<int> v = divideNumbers(format);
    int cur = 0;
    bool flag = false;
    for (int i = 0; i < v.size(); ++i)
    {
        if (flag == true)
        {
            fout << " ";
        }
        else
        {
            flag = false;
        }
        readString(pNumber.substr(cur, v[i]));
        cur += v[i];
    }


}

void readString(string s)
{
    int sz = s.size();
    int cur = 0;
    bool flag = false;
    while (cur < sz)
    {
        int next = cur + 1;
        while (next < sz && s[next] == s[cur])
        {
            next++;
        }

        if (flag = false)
        {
            flag = true;
        }
        else
        {
            fout << " ";
        }

        switch (next - cur)
        {
            case 1: fout << spellNumber(s[cur] - '0');
                    break;
            case 2: fout << "double " << spellNumber(s[cur] - '0');
                    break;
            case 3: fout << "triple " << spellNumber(s[cur] - '0') ;
                    break;
            case 4: fout << "quadruple " << spellNumber(s[cur] - '0');
                    break;
            case 5: fout << "quintuple " << spellNumber(s[cur] - '0') ;
                    break;
            case 6: fout << "sextuple " << spellNumber(s[cur] - '0') ;
                    break;
            case 7: fout << "septuple " << spellNumber(s[cur] - '0') ;
                    break;
            case 8: fout << "octuple " << spellNumber(s[cur] - '0') ;
                    break;
            case 9: fout << "nonuple " << spellNumber(s[cur] - '0') ;
                    break;
            case 10: fout << "decuple " << spellNumber(s[cur] - '0') ;
                    break;
        }
        
        cur = next;
    }
}

vector<int> divideNumbers(const string& format)
{
    vector<int> v;
    for (int i = 0; i < format.size(); ++i)
    {
        if (format[i] != '-')
        {
            int next = i + 1;
            while (next < format.size() && next != '-')
            {
                next++;
            }
            v.push_back(atoi((format.substr(i, next-i)).c_str()));
        }
    }
    return v;
}

int main()
{
    int N = 0;
    ifstream fin("A-small-attempt0.in", ios::in);
    if (!fin.is_open())
    {
        cerr << "Cannot read !" << endl;
        return -1;
    }
    fin >> N;
    vector<pair<string, string> > v(N);
    string s, f;
    for (int i = 0; i < N; ++i)
    {
        fin >> s >> f;
        v[i].first = s;
        v[i].second = f;
    }
    fin.close();


    for (int i = 0; i < N; ++i)
    {
        fout << "Case #" << i + 1 << ":" ;
        readPhoneNumber(v[i].first, v[i].second);
        fout << endl;
    }
    
    return 0;
}