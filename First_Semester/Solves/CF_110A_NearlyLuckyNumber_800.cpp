#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int qt = 0;

    for (char c : s)
    {
        if (c == '4' || c == '7')
        {
            qt++;
        }
    }

    for (char c : to_string(qt))
    {
        if (c != '4' && c != '7')
        {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

int main()
{
    int t = 1;
    // cin >> t;

    while (t--)
        solve();

    return 0;
}
