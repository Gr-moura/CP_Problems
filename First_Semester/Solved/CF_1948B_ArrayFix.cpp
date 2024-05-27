#include <bits/stdc++.h>
using namespace std;

int main(){
    int vezes, add, no, temp; 
    cin >> vezes;

    while (vezes--)
    {
        no = 0;
        vector <int> v;
        int qt_num; 
        cin >> qt_num;

        for (int i = 0; i < qt_num; i++)
        {
            cin >> add;
            v.push_back(add);
        }

        for (int i = v.size() - 1; i > 0; i--)
        {
            if (v[i] < v[i - 1] && v[i - 1] > 9) 
            {
                temp = v[i - 1];
                v[i - 1] = v[i - 1] / 10;
                v.insert(v.begin() + i, temp % 10);
                i = i + 1;

            } 
            
            if (v[i] < v[i - 1] && v[i - 1] <= 9)
            {
                no = 1;
                break;

            }
        }

        if (no) cout << "NO\n";
        else cout << "YES\n";




    }

    return 0;
}