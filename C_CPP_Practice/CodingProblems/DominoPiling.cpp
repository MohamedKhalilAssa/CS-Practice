/*
A. Domino Piling - 50A
link : https://codeforces.com/problemset/problem/50/A
*/

#include <iostream>

using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;

    int mult = m * n;
    // since each domino take two squares then
    //    since int will take only the integer part
    cout << mult / 2;
    return 0;
}
