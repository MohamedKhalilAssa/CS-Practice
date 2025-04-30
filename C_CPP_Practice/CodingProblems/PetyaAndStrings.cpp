/*
A. Integer Moves - 112A
link : https://codeforces.com/problemset/problem/112/A
*/

#include <iostream>

using namespace std;

void turnIntoLowerC(string &s)
{

    int size = s.length();

    for (int i = 0; i < size; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = (s[i] - 'A') + 'a';
        }
    }
}

int main()
{
    string a, b;
    cin >> a >> b;
    turnIntoLowerC(a);
    turnIntoLowerC(b);
    // Since it is garanteed to have same lengths strings we won t bother with the test
    if (a < b)
        cout << -1;
    else if (a > b)
        cout << 1;
    else
        cout << 0;
    return 0;
}
