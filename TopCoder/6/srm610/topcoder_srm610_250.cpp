#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;

int CountNumbers(vector <int> numbers)
{    
    set<int> tmp(numbers.begin(), numbers.end());
    do{
        numbers.resize(tmp.size());
        copy(tmp.begin(), tmp.end(), numbers.begin());
        for (int i = 0; i < numbers.size(); ++i)
        {
            for (int j = i + 1; j < numbers.size(); ++j)
            {
                int a = numbers[i];
                int b = numbers[j];
                if (a < b)
                {
                    swap(a, b);
                }

                if (find(tmp.begin(), tmp.end(), a / b) == tmp.end())
                {
                    tmp.insert(a / b);
                }
            }
        }
    }while(numbers.size() != tmp.size());

    return tmp.size();
}

#if 0
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
#endif //0