#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<int> numbers;
    string s;
    getline(cin, s);
    for (int k = 0; k < s.size(); k += 2)
    {
        numbers.push_back(s[k]-'0');
    }
    cout << "vectors:" << endl;
    for (auto it = numbers.begin(); it != numbers.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    for (int i = 0; i < numbers.size() - 2; i += 2)
    {
        int a = numbers[i];
        int b = numbers[i+1];
        if (b != 0)
        {
            cout << a * b << " " << b - 1 << " ";
        }
        else
        {
            cout << 0 << " " << 0 << " "; 
        }
    }

    int a = numbers[numbers.size()-2];
    int b = numbers[numbers.size()-1];
    
    if (b != 0)
    {
        cout << a * b << " " << b - 1 << endl;;
    }
    else
    {
        cout << 0 << " " << 0 << endl;
    }
    return 0;
}
