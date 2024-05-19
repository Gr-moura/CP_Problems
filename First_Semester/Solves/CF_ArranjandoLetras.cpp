#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int vezes;
    cin >> vezes;
    char a;
    string str;
    for (int i = 0; i<vezes; i++){
        cin >> str;
        a = str[0];
        for (int k = 0; k < str.size(); k++){
            if (str[k] != a){
                sort(str.begin(),str.end());
                cout <<str<<"\n";
                break;
            } else if (k == str.size() - 1){
                printf ("-1\n");
            }
        }

    }





    return 0;
}
