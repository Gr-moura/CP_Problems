    #include <bits/stdc++.h>
    using namespace std;
     
    int main(){
        int x,y;
        cin >> x >> y;
        string a[100];
        for (int i = 0; i<x;i++){
            cin >> a[i];
        }
        for (int i = 0; i <= x+ 1; i++){
            for (int j = 0; j<= y+1; j++){
     
                if (i!= 0 && i!= x+1 && j == 0){
                    cout<<"#"<<a[i-1]<<"#\n";
                    break;
                }
                if (j == y+1){
                    cout<<"#\n";
                    break;
                }
                if (i == 0){
                    cout<<"#";
                }
                if(i==x+1){
                    cout<<"#";
     
                }
            }
        }
   
    	return 0;
    }
