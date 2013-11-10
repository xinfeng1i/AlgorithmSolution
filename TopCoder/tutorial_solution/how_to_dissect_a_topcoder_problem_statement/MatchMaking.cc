#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;

class MatchMaking
{
public:


string makeMatch(vector<string> namesWomen, vector<string> answersWomen,
                 vector<string> namesMen, vector<string> answersMen,
                 string queryWoman)
{
    map<string, string> ans_match;

    map<string, string> women_ans;
    map<string, string> men_ans;
    
    int n = namesWomen.size();
    for (int i = 0; i < n; ++i)
    {
        women_ans.insert(pair<string, string>(namesWomen[i], answersWomen[i]));
    }

    for (int i = 0; i < n; ++i)
    {
        men_ans.insert(pair<string, string>(namesMen[i], answersMen[i]));
    }

    map<string, string>::iterator women_it;
    map<string, string>::iterator men_it;
    for (women_it = women_ans.begin(); women_it != women_ans.end(); ++women_it)
    {
        string ans1 = women_it->second;
        int max_cnt = 0;
        string match_men;
        for (men_it = men_ans.begin(); men_it != men_ans.end(); ++men_it)
        {
            string ans2 = men_it->second;
            int cnt = 0;
            for (int k = 0; k < ans1.size(); ++k)
            {
                if (ans1[k] == ans2[k])
                {
                    cnt++;
                }
            }

            if (cnt > max_cnt)
            {
                max_cnt = cnt;
                match_men = men_it->first;
            }
        }

        ans_match[women_it->first] = match_men;
        // remember delete the used men
        men_ans.erase(match_men);
    }

    return ans_match[queryWoman];
}

};

