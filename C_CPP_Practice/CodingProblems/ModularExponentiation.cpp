/*
A. Modular Exponentiation - 913A
link : https://codeforces.com/problemset/problem/913/A
*/

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    long long n, m;

    cin >> n >> m;
    if (n >= 60)
    {
        cout << m << endl;
        return 0;
    }
    unsigned long long result = 1, base = 2;
    long long exp = n;

    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result *= base;
        }

        base *= base;
        exp /= 2;
    }

    cout << m % result << endl;
    return 0;
}