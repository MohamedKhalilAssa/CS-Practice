/*
Anton and Danik - 734A
link : https://codeforces.com/problemset/problem/734/A
*/

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int anton = 0, danik = 0;
    // Calculation of number of winning for each
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'A')
            anton++;
        else if (s[i] == 'D')
            danik++;
        else
            continue;
    }
    // Conditional statements
    if (anton > danik)
        cout << "Anton" << endl;
    else if (danik > anton)
        cout << "Danik" << endl;
    else
        cout << "Friendship" << endl;

    return 0;
}
