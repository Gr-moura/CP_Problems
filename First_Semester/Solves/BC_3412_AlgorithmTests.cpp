#include <bits/stdc++.h>
using namespace std;

#define _                                                                                                              \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);
#define endl '\n'
int main()
{
    _ cout << fixed << setprecision(1);
    int t = 1;
    cin >> t;
    string name, surname, temp;
    double num, total = 0;
    cin >> name;
    while (t--)
    {
        int sobrenome = 0;
        total = 0;
        cout << name;

        double min = 11;

        while (cin >> temp && temp[0] - '0' > 9)
        {
            cout << " " << temp << ": ";
            sobrenome = 1;
        }

        if (!sobrenome)
            cout << ": ";

        int size = 1;
        num = temp[0] - '0' + (temp[2] - '0') / 10.0;
        total += num;
        min = num;

        while (cin >> temp && temp[0] - '0' >= 0 && temp[0] - '0' <= 9)
        {
            num = temp[0] - '0' + (temp[2] - '0') / 10.0;
            total += num;
            size++;

            if (num < min)
                min = num;
        }

        name = temp;

        if (size <= 2)
            cout << total / 2.0 << endl;

        else
        {
            if (size == 4)
                total -= min;
            cout << total / 3.0 << endl;
        }
    }

    return 0;
}
