    /*
    AWayTooLongWord - 71A
    link : https://codeforces.com/problemset/problem/71/A
    */

    #include <iostream>

    using namespace std;

    int strLen(string s)
    {
        int n = 0;

        while (s[n] != '\0')
            n++;

        return n;
    }
    string substring(string s, int start, int end)
    {
        string result = "";
        for (int i = start; i < end; i++)
            result += s[i];
        return result;
    }
    string itoa(int i)
    {
        string ch = "";

        while (i > 0)
        {
            ch = char(i % 10 + '0') + ch;
            i /= 10;
        }
        return ch;
    }
    int main()
    {
        int n;
        cin >> n;

        while (n-- > 0)
        {
            string s;
            cin >> s;
            int size = strLen(s);
            if (size <= 10)
                cout << s << endl;
            else
            {
                string result = "";
                result += s[0] + itoa(size - 2) + s[size - 1];
                cout << result << endl;
            }
        }

        return 0;
    }
