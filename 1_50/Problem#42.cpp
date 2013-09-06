#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

vector<int> triNumbers(100);

bool isWordValue(string word)
{
    int sum = 0;
    for(size_t i = 0; i < word.size(); ++i)
    {
        sum += word[i] - 'A' + 1;
    }

    if (binary_search(triNumbers.begin(), triNumbers.end(), sum))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    for(int i = 0; i < 100; i++)
    {
        triNumbers[i] = (i + 1) * (i + 2) / 2;
    }
    cout << triNumbers[0] << endl;
    cout << triNumbers[99] << endl;

    string word;
    int count_triangle_word = 0;
    ifstream fin("Problem#42_data.txt", ios::in);
    if (!fin.is_open())
    {
        cerr << "Cannot Open File to Read " << endl;
        exit(1);
    }
    while (getline(fin, word, ','))
    {
        if ( isWordValue(word.substr(1, word.size()-2)) )
        {
            count_triangle_word++;
        }
    }
    fin.close();

    cout << "Number of triangle word: " << count_triangle_word << endl;
    return 0;
}
