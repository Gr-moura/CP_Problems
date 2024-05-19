    #include <bits/stdc++.h>
    using namespace std;
     
    int main(){
        string a,b;
        char achar;
        cin >>a;
        b = a;
        sort(a.begin(),a.end());
        if (a[0] == a[1]) {
            achar = a[a.size()-1];
        } else achar = a[0];
     
        cout<<b.find(achar)+1;
     
     
     
    	return 0;
    }
