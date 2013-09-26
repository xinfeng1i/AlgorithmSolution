#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdio>
using namespace std;

struct Student
{
    string id_;
    int score_;
    int location_;
    int localRank_;
    int finalRank_;
};

bool compareStudent(const Student &a, const Student& b)
{
    if (a.score_ == b.score_)
    {
        return a.id_ < b.id_;
    }
    else
    {
        return a.score_ > b.score_;
    }
}

int main()
{
    //freopen("1025data.txt", "r", stdin);
    int N = 0;
    int K = 0;
    cin >> N;
    vector<Student> list;
    for (int i = 0; i < N; ++i)
    {
        cin >> K;
        vector<Student> tmplist(K);     //tmplist to sort local lists

        // read local list, set the local number
        for (int j = 0; j < K; ++j)
        {
            cin >> tmplist[j].id_ >> tmplist[j].score_;
            tmplist[j].location_ = i + 1;
        }
        // sort local list
        sort(tmplist.begin(), tmplist.end(), compareStudent);

        vector<int> tmpscores;  // helper vector only contained local scores
        for (int j = 0; j < K; ++j)
        {
            tmpscores.push_back(tmplist[j].score_);
        }

        
        // calculate local rank
        for (int j = 0; j < K; ++j)
        { 
            auto low = lower_bound(tmpscores.begin(), 
                                   tmpscores.end(),
                                   tmplist[j].score_,
                                   greater<int>());
            tmplist[j].localRank_ = low - tmpscores.begin() + 1;
        }

        // append local list to the global list
        list.insert(list.end(), tmplist.begin(), tmplist.end());
    }
    
    // sort global list
    sort(list.begin(), list.end(), compareStudent);

    
    // extract all the scores int to a vector
    vector<int> globalScores(list.size(), 0);
    for (int i = 0; i < list.size(); ++i)
    {
        globalScores[i] = list[i].score_;
    }

    // calculate global rank
    for (int i = 0; i < list.size(); ++i)
    {
        auto low = lower_bound(globalScores.begin(),
                               globalScores.end(),
                               list[i].score_, 
                               greater<int>());
        list[i].finalRank_ = low - globalScores.begin() + 1;
    }

    cout << list.size() << endl;
    for (int i = 0; i < list.size(); ++i)
    {
        cout << list[i].id_ << " "
             << list[i].finalRank_ << " "
             << list[i].location_ << " "
             << list[i].localRank_ << endl;
    }

    return 0;

}
