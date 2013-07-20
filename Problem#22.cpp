#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{

    clock_t time_begin = clock();

    vector<string> svec;

    // read file, store it into memory--svec
    ifstream fin("Problem#22_data.txt", ios_base::in);
    if (fin.is_open())
    {
        string s;
        while (!fin.eof())
        {
            getline(fin, s, ',');
            s = s.substr(1,s.size()-2); // drop the [""]
            svec.push_back(s);
        }
        // adjust last words, cause it has an ENTER space
        svec[svec.size()-1] = "ALONSO";
        fin.close();
    }
    else
    {
        cerr << "Cannot Open the file ! " << endl;
    }


    // sort the name
    sort(svec.begin(), svec.end());

    long long totalSum = 0;
    int index = 0;
    for (int i = 0; i < svec.size(); i++)
    {
        index = i + 1;  // word position in alphabetical order

        string s = svec[i];
        int wordsValue = 0; // every word value count
        for (int j = 0; j < s.size(); j++)
        {
            wordsValue += s[j] - 'A' + 1;
        }

        totalSum += index * wordsValue;
        
    }
    
    cout << "Totol Sum: " << totalSum << endl;
    
    clock_t time_end = clock();
    double time_cost = (double)(time_end - time_begin) / CLOCKS_PER_SEC;
    cout << "TIME COST: " << time_cost << " s" << endl;
    return 0;
}
