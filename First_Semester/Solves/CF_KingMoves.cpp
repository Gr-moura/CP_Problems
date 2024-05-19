#include <bits/stdc++.h>
using namespace std;

int main()
{
    char s[3];
    fgets(s,3,stdin);
    char column = s[0], row = s[1];
    if ((column == 'a' || column == 'h') && (row == '1' || row == '8')){
        printf("3");
    } else if (column == 'a' || column == 'h'){
        printf("5");
    } else if (row == '1' || row == '8'){
        printf("5");
    } else{
        printf("8");
    }
    return 0;
}
