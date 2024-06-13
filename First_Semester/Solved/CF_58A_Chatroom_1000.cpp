#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a;
    cin >> a;
    string b = "hello";
    int ib = 0;

    for (auto c : a)
    {
        if (b[ib] == c)
            ib++;
        if (ib == 5)
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}
