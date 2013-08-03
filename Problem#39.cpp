#include <iostream>
#include <string>
#include <ctime>

using namespace std;

/* Given a perimeter |p|, return the number of possible triangle (a,b,c)
 * whose perimeter equals to p and have a right angle
 * i.e. Satify to: a + b + c = p && a^2 + b^2 = c^2
 */
int numTriangle(int p)
{
    int cnt = 0;
    int c = 0;
    for (int a = 1; a <= p / 3; a++)
    {
        for (int b = a; b < p / 2; b++)
        {
            c = p - a - b;
            if (a * a + b * b == c * c)
            {
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    clock_t time_begin = clock();

    int max_num_triangle = 0;
    int max_perimeter = 0;

    int num_triangle = 0;
    for (int p = 3; p <= 1000; p++)
    {
        num_triangle = numTriangle(p);
        if (num_triangle > max_num_triangle)
        {
            max_num_triangle = num_triangle;
            max_perimeter = p;
        }
    }

    cout << "Max Perimeter: " << max_perimeter << endl;
    cout << "Number of Triangles: " << max_num_triangle << endl;

    clock_t time_end = clock();
    double time_cost = (double)(time_end - time_begin) / CLOCKS_PER_SEC;
    cout << "TIME COST: " << 1000 * time_cost << " ms" << endl;
    return 0;
}
