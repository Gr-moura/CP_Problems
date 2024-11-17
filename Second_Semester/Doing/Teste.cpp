#include "Headers.h"
#include <bits/stdc++.h>
using namespace std;
void f()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, l;
        cin >> n >> m >> l;
        vector<pair<int, int>> a(n), b(m);
        for (int i = 0; i < n; ++i)
            cin >> a[i].first >> a[i].second;
        for (int i = 0; i < m; ++i)
            cin >> b[i].first >> b[i].second;
        reverse(b.begin(), b.end());
        multiset<int> s;
        int u = 1, v = 0;
        for (auto [x, y] : a)
        {
            int w = y + 2 - x;
            while (b.size() && b.back().first < x)
                s.insert(b.back().second), b.pop_back();
            while (!s.empty() && u < w)
                u += *s.rbegin(), s.erase(prev(s.end())), v++;
            if (u < w)
            {
                v = -1;
                break;
            }
        }
        cout << v << endl;
    }
}
int main()
{
    f();
}
