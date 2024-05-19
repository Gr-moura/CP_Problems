#include <bits/stdc++.h>
using namespace std;
int main(){

    int vezes, quantos, num, median_index, median, count;
    vector <int> v;
    cin >> vezes;
    while (vezes --){
        count = 0;
        v.clear();
        cin >> quantos;
        median_index = (quantos + 1)/2 - 1;

        while (quantos --){
            cin >> num;
            v.push_back(num);
        }

        sort(v.begin(), v.end());
        median = v[median_index];

        for (int i = median_index ; v[i] == median; i++){
            count ++;
            if (i == v.size() - 1){
                break;
            }
        }

        cout << count<<"\n";


    }



    return 0;
}
