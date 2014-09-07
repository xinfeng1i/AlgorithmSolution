#include <iostream>
#include <string>
#include <ctime>

using namespace std;

const int DIGIT_LENGTH = 300;
const int FACTORIAL_N = 100;

int main()
{
    clock_t time_begin = clock();

    int digits[DIGIT_LENGTH] = {0};
    digits[0] = 1;
    for (int n = 1; n <= FACTORIAL_N; n++)
    {
        for (int i = 0; i < DIGIT_LENGTH; i++)
        {
            digits[i] *= n;
        }
        for (int i = 0; i < DIGIT_LENGTH; i++)
        {
            if (digits[i] >= 10)
            {
                digits[i+1] += digits[i] / 10;
                digits[i] = digits[i] % 10;
            }
        }
    }
    
    // printf FACTORIAL_N !
    cout << "The " << FACTORIAL_N << "! is: " << endl;
    int firstNoZeros = DIGIT_LENGTH - 1;
    while (digits[firstNoZeros] == 0)
    {
        firstNoZeros--;
    }
    for (int i = firstNoZeros; i >= 0; i--)
    {
        cout << digits[i];
    }
    cout << endl;

    // printf sum of the digits
    long long sum = 0;
    for (int i = firstNoZeros; i >= 0; i--)
    {
        sum += digits[i];
    }
    cout << "Sum of the digits is: " << sum << endl;

    clock_t time_end = clock();
    double time_cost = (double)(time_end - time_begin) / CLOCKS_PER_SEC;
    cout << "TIME COST:" << time_cost << " s" << endl;
    return 0;
}
