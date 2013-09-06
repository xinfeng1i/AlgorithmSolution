#include <iostream>
#include <string>

using namespace std;

int cntLetters(int number)
{
    if (number < 0 || number > 1000)
    {
        cerr << "Parameter Wrong! " << endl;
        return -1;
    }

    if (number == 0)
    {
        return 0;
    }

    if (number <= 10)
    {
        switch(number)
        {
            case 1:
            case 2:
            case 6:
            case 10:
            return 3;
            break;

            case 4:
            case 5:
            case 9:
            return 4;
            break;
            
            case 3:
            case 7:
            case 8:
            return 5;
            break;

            default:
            break;
        }
    }
    else if (number <= 19)
    {
        switch (number)
        {
            case 11:
            case 12:
                return 6;
                break;
            case 13:
            case 14:
            case 18:
            case 19:
                return 8;
                break;
            case 15:
            case 16:
                return 7;
                break;
            case 17:
                return 9;
                break;
            default:
                break;
        }
    }
    else if (number <= 99)
    {
        switch (number / 10)
        {
            case 2:
            case 3:
            case 8:
            case 9:
                return 6 + cntLetters(number % 10);
                break;
            case 4:
            case 5:
            case 6:
                return 5 + cntLetters(number % 10);
                break;
            case 7:
                return 7 + cntLetters(number % 10);
                break;
            default:
                break;

        }
    }
    else if (number <= 999)
    {
        // 100, 200, 300, ... 900, not include "and"
        if (number % 100 == 0)
        {
            return cntLetters(number / 100) + 7;
        }
        else    // 134,345... and so on, include "and"
        {
            return cntLetters(number / 100) + 7 + 3 + cntLetters(number % 100); 
        }
    }

    else if (number == 1000)
    {
        return 3 + 8;
    }
}

int main()
{
    int letter_count = 0;
    for (int i = 1; i <= 1000; i++)
    {
        letter_count += cntLetters(i);
    }

    cout << "All Letters Count between 1 and 1000 is :" 
        << letter_count << endl;
    return 0;
}
