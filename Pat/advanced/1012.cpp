#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    // read input
    int N, M;
    cin >> N >> M;
    
    map<string, vector<int> > stuGrades;
    string s;
    vector<int> v(4, 0);
    for (int i = 0; i < N; ++i)
    {
        cin >> s;
        cin >> v[0] >> v[1] >> v[2];
        stuGrades.insert(pair<string, vector<int> >(s, v));
    }

    queue<string> requestQueue;
    string tmp;
    for (int j = 0; j < M; ++j)
    {
        cin >> tmp;
        requestQueue.push(tmp);
    }

    // classify grades by C, M, E, A
    vector<int> vc(N, 0);
    vector<int> vm(N, 0);
    vector<int> ve(N, 0);
    vector<int> va(N, 0);
    auto itmap = stuGrades.begin();
    for (int i = 0; i < N; ++i, ++itmap)
    {
        vc[i] = itmap->second[0];
        vm[i] = itmap->second[1];
        ve[i] = itmap->second[2];
        va[i] = round((vc[i] + vm[i] + ve[i]) / 3.0);
        itmap->second[3] = va[i];
    }

    sort(vc.begin(), vc.end(), greater<int>());
    sort(vm.begin(), vm.end(), greater<int>());
    sort(ve.begin(), ve.end(), greater<int>());
    sort(va.begin(), va.end(), greater<int>());

    while (!requestQueue.empty())
    {
        string s = requestQueue.front();
        requestQueue.pop();
        if (stuGrades.find(s) == stuGrades.end())
        {
            cout << "N/A" << endl;
        }
        else
        {
            int gradeC = stuGrades[s][0];
            int gradeM = stuGrades[s][1];
            int gradeE = stuGrades[s][2];
            int gradeA = stuGrades[s][3];

            int rankC = find(vc.begin(), vc.end(), gradeC) - vc.begin() + 1;
            int rankM = find(vm.begin(), vm.end(), gradeM) - vm.begin() + 1;
            int rankE = find(ve.begin(), ve.end(), gradeE) - ve.begin() + 1;
            int rankA = find(va.begin(), va.end(), gradeA) - va.begin() + 1;

            int minRank = rankA;
            char minch = 'A';
            if (rankC < minRank)
            {
                minRank = rankC;
                minch = 'C';
            }

            if (rankM < minRank)
            {
                minRank = rankM;
                minch = 'M';
            }

            if (rankE < minRank)
            {
                minRank = rankE;
                minch = 'E';
            }
            cout << minRank << " " << minch << endl;
        }
    }

    return 0;
}
