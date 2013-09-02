#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    
    string line;
    getline(cin, line, '\n');

    stringstream ss;
    ss << line;

    vector<string> svec;
    string word;
    while (ss >> word)
    {
        svec.push_back(word);
    }

    for (size_t i = svec.size() - 1; i > 0; i--)
    {
        cout << svec[i] << " ";
    }
    cout << svec[0] << endl;
    return 0;
}
