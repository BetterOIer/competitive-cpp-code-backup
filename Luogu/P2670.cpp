#include<iostream>
using namespace std;
int a[105][105]={};
int main(){
    int m,n;
    char c;
    cin>>m>>n;
    for(int i = 1;i<=m;i++){
        for(int w = 1;w<=n;w++){
            cin>>c;
            if(c=='*'){
                a[i][w]=9;
            }
        }
    }
    
    for(int i = 1;i<=m;i++){
        for(int w = 1;w<=n;w++){
            if(a[i][w]!=9){
                if(a[i][w+1]==9){
                    a[i][w]++;
                }
                if(a[i][w-1]==9){
                    a[i][w]++;
                }
                if(a[i+1][w]==9){
                    a[i][w]++;
                }
                if(a[i-1][w]==9){
                    a[i][w]++;
                }
                if(a[i+1][w+1]==9){
                    a[i][w]++;
                }
                if(a[i+1][w-1]==9){
                    a[i][w]++;
                }
                if(a[i-1][w+1]==9){
                    a[i][w]++;
                }
                if(a[i-1][w-1]==9){
                    a[i][w]++;
                }
            }
        }  
    }
    for(int i = 1;i<=m;i++){
        for(int w = 1;w<=n;w++){
            if(a[i][w]==9){
                cout<<'*';
            }else{
                cout<<a[i][w];
            }
        }
        cout<<endl;
    }
    return 0;
} 