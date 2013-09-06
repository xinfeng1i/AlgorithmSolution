#include <iostream>
#include <string>
#include <cassert>
#include <cmath>
#include <ctime>

using namespace std;

/*************************************************************
 * Acording to the definition, A curious fraction must satisfy 
 * the form : ab/bc == a / c
 *
 * Input:
 * nume --- nume
 * deno --- deno
 * 
 * Return:
 * whether nume / deno is a curious fraction
 *************************************************************/
bool isCuriousFraction(int nume, int deno)
{
    assert(nume >= 10 && nume <= 99);
    assert(deno >= 10 && deno <= 99);
    if (nume % 10 != deno / 10) // don't have common |b|, false
    {
        return false;
    }
    else
    {
        int a = nume / 10;
        int c = deno % 10;
        double original = static_cast<double>(nume) / deno;
        double simple = static_cast<double>(a) / c;
        if (abs(original - simple) < 1e-5)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

int main()
{
    clock_t time_begin = clock();

    int product_nume = 1;
    int product_deno = 1;
    for (int i = 10; i < 100; i++)
    {
        for (int j = i + 1; j < 100; j++)
        {
            if (isCuriousFraction(i, j))
            {
                cout << "i=" << i << "  " << "j=" << j << endl;
                product_nume *= i;
                product_deno *= j;
            }
        }
    }
    cout << "product: " << product_nume << " / " << product_deno << endl;

    clock_t time_end = clock();
    double time_cost = (double)(time_end - time_begin) / CLOCKS_PER_SEC;
    cout << "TIME COST: " << time_cost << endl;

    return 0;
}
