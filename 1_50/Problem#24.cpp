#include <iostream>
#include <string>
#include <vector>
#include <algorithm> //std::next_permutation
#include <ctime>

using namespace std;

#if 1
vector<string> g_svec;
void permutation(string sofar, string rest)
{
    if (rest == "")
    {
        g_svec.push_back(sofar);
    }

    for (int i = 0; i < rest.size(); i++)
    {
        string sofar_new = sofar + rest[i];
        string remain = rest.substr(0, i) + rest.substr(i+1, rest.size()-i-1);
        permutation(sofar_new, remain);
    }
}

int main()
{
    clock_t time_begin = clock();

    permutation("", "0123456789");
    cout << g_svec[1000000 - 1] << endl;

    clock_t time_end = clock();
    double time_cost = (double)(time_end - time_begin)/CLOCKS_PER_SEC;
    cout << "TIME COST: " << time_cost << " s" << endl; 
    return 0;
}
#endif

/* Method 2 */
/*
int main()
{
    const long long UP_LIMIT = 1000000;

    string digits = "0123456789";
    long long permutation_cnt = 1;
    while(next_permutation(digits.begin(), digits.end()))
    {
        permutation_cnt++;
        if (permutation_cnt >= UP_LIMIT)
            break;
    }

    cout << "count: " << permutation_cnt << endl;
    cout << digits << endl;;
    return 0;
}
*/
