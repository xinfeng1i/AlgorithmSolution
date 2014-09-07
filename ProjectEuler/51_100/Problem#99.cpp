#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>
using namespace std;

/* return log(a^b) = b*log(a)
 */
double maxLogAB(double a, double b)
{
    return b * log10(a);
}

int main()
{
    const int LINE_NUM = 1000;
    vector<vector<int> > numbers(LINE_NUM); // container to numbers
    for (int i = 0; i < LINE_NUM; ++i)
    {
        numbers[i].resize(2);
    }

    ifstream fin("Problem#99_data.txt", ios::in);
    if (!fin.is_open())
    {
        cerr << "Cannot open file to read" << endl;
        return -1;
    }

    for (int i = 0; i < numbers.size(); ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            fin >> numbers[i][j];
        }
    }
    fin.close();

    double max_number = 0;
    int max_line_number = -1;
    for (int i = 0; i < numbers.size(); ++i)
    {
        double tmp = maxLogAB(numbers[i][0], numbers[i][1]);
        if (tmp > max_number)
        {
            max_number = tmp;
            max_line_number = i + 1;
        }
    }

    cout << "largest number find in line " << max_line_number << endl;
    return 0; 
}
