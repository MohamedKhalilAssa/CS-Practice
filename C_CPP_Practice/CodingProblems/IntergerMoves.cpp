/*
A. Integer Moves - 1657A
link : https://codeforces.com/problemset/problem/1657/A
*/

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int x, y;
        cin >> x >> y;
        double formula = sqrt(x * x + y * y);
        if (x == 0 && y == 0)
        {
            cout << 0 << endl;
        }
        else if (formula == (int)formula)
        {
            cout << 1 << endl;
        } else {
            cout << 2 << endl;
            // this is because we can move through Y once then through X, for optimized intermediary point we can use perfect Triangles (Pythagorian Theorem)
        }
    }

    return 0;
}
