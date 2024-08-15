#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<pair<int, int>> p;
    set<pair<int, int>> p2;

    p.insert({0, 1});
    p.insert({1, 0});

    p2.insert({0, 1});
    p2.insert({1, 0});

    pair<int, int> ua = {1, 0};
    pair<int, int> ub = {1, 0};

    for (auto j : p)
    {
        p.insert({j.first + 2, j.second});
        p.insert({j.first, j.second + 2});

        if (p.size() == 200)
            break;
    }

    for (auto j : p2)
    {
        p2.insert({j.first + 2, j.second});
        p2.insert({j.first, j.second + 2});
        p2.insert({j.first + 1, j.second + 1});

        if (p2.size() == 200)
            break;
    }

    vector<pair<int, int>> a;
    vector<pair<int, int>> b;

    for (auto j : p)
    {
        a.push_back(j);
        if (a.size() == 150)
            break;
    }

    for (auto j : p2)
    {
        b.push_back(j);
        if (b.size() == 150)
            break;
    }

    for (int i = 0; i < 150; i++)
    {
        if (a[i] != b[i])
        {
            cout << a[i].first << " " << a[i].second << " | " << b[i].first << " " << b[i].second << endl;
        }
    }

    return 0;
}
