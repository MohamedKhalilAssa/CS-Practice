/*
And Then There Were K  - 1527A
link : https://codeforces.com/problemset/problem/1527/A
*/
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int power = 1;
        while (power <= n)
        {
            power *= 2;
        }

        cout << power / 2 - 1 << endl;
    }
    return 0;
}
