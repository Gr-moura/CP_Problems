#include <bits/stdc++.h>
using namespace std;

int main(){
    char a[104], b[104];
    fgets(a, 104, stdin);
    fgets(b, 104, stdin);

    for (int i = 0; a[i] !='\n'; i++){
        if (a[i] != b[i]){
            cout << '1';
        } else {
            cout << '0';
        }
    }



    return 0;
}
