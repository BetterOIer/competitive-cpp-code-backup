#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int t,n,m,ansx,ansy;
    scanf("%d",&t);
    for(;t--;){
        scanf("%d%d",&n,&m);
        for(int j=1;j<=sqrt(n)+1;j++){
            if(n%j==0){
                ansx=j;
                ansy=n/j;
            }
        }
        if(ansx*2+ansy*2+4<=m){
            cout<<"Good"<<endl;
        }
        else cout<<"Miss"<<endl;
    }
} 