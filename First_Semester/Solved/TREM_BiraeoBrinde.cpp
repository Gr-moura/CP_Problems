#include <bits/stdc++.h>
using namespace std;


int main(){
    int vezes, qtnum;
    long long num;
    scanf("%d ", &vezes);
    vector <long long> v;

    for (int i = 0; i<vezes; i++){
        v.clear();
        scanf("%d ", &qtnum);
        for (int k = 0; k<qtnum; k++){
            scanf("%lld ", &num);
            v.push_back(num);
        }

        sort(v.begin(),v.end());
        if (v[0]*v[1] > v[v.size() - 1]*v[v.size() - 2]){
            printf("%lld\n",v[0]*v[1]);

        }else{
            printf("%lld\n",v[v.size() - 1]*v[v.size() - 2]);
        }


    }


    return 0;
}
