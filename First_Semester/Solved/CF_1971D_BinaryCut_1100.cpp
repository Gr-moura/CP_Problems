#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int ans = 0;
        int tirar = 0;
        string a;
        cin >> a;
        char ultimo = a[0];
        for (int i = 0; i < a.size(); i++)
        {
            char c = a[i];

            if (c != ultimo)
                ans++;
            if (i + 1 < a.size() && c == '0' && a[i + 1] == '1')
                tirar = 1;
            ultimo = c;
        }

        cout << ans - tirar + 1 << endl;
    }
    return 0;
}
