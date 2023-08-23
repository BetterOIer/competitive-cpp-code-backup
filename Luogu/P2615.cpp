#include<iostream>
using namespace std;
int huan[40][40]={};
int main(){
    int n, a, b;
    cin>>n;
    a =1;
    b = (n+1)/2;
    huan[a][b] = 1;
    for(int k = 2;k<=n*n;k++){
        if(a == 1&&b!=n){
            huan[n][b+1] = k;
            a = n;
            b = b+1;
            continue;
        }
        else if(b==n&&a!=1){
            huan[a-1][1] = k;
            a = a-1;
            b = 1;
            continue;
        }
        else if(b==n&&a==1){
            huan[a+1][b] = k;
            a = a+1;
            continue;
        }
        else if(b!=n&&a!=1){
            if(!huan[a-1][b+1]){
                huan[a-1][b+1] = k;
                a = a-1;
                b = b+1;
                continue;
            }
            else{
                huan[a+1][b]=k;
                a = a+1;
                continue;
            }
        }
    }
    for(int i = 1;i<=n;++i){
        for(int w = 1;w<=n;++w){
            cout<<huan[i][w]<<" ";
        }
        cout<<endl;
    }
    return 0;
} 