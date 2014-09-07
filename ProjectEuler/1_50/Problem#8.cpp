#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

int main()
{
    ifstream fin("Problem#8_data.txt", ios_base::binary);
    if (fin.is_open())
    {
        fin.seekg(0,fin.end);
        int length = fin.tellg();
        fin.seekg(0,fin.beg);
        
        // read data form file to buffer
        char* buffer = new char [length];
        fin.read(buffer, length);
        
        fin.close();

        // extract data from buffer to vector
        vector<int> ivec;
        for (int i = 0; i < length; i++)
        {
            if (buffer[i] >= '0' && buffer[i] <= '9')
            {
                int tmp = buffer[i] - '0';
                ivec.push_back(tmp);
            }
        }
        delete[] buffer;

        // data processing
        clock_t time_begin = clock();

        cout << "ivec size: " << ivec.size() << endl;
        long long maxProduct = 0;
        long long curProduct = 0;
        for (int i = 0; i <= ivec.size() - 5; i++)
        {
            curProduct = ivec[i] * ivec[i+1] * ivec[i+2] * ivec[i+3] * ivec[i+4];
            if (curProduct > maxProduct)
            {
                maxProduct = curProduct;
            }
        }
        cout << "Largest Product in a series:" << maxProduct << endl;
        
        clock_t time_end = clock();
        double time_cost = (double)(time_end - time_begin) / CLOCKS_PER_SEC;
        cout << "TIME COST: " << time_cost << " s" << endl;
    }
    return 0;
}
