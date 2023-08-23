#include<iostream>
using namespace std;
long long a[1000001];
int main(){
    int n,m,opt;
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    for(int i = 1;i<=m;i++){
        cin>>opt;
        int L=1,R=n;
        bool flag = false;
        while(L<=R){
            int M = L+(R-L)/2;
            if(a[M]==opt){
                R=M-1;
                flag=true;
            }else if(a[M]>opt){
                R=M-1;
            }else if(a[M]<opt){
                L=M+1;
            }
        }
        if(flag){
            cout<<L<<" ";
        }
        else{
            cout<<-1<<" ";
        }
    }
    return 0;
} 