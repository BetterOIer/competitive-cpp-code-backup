#include<iostream>
using namespace std;
unsigned long long A1=1,A2=1,A3=1,A4=1,C1=1,C2=1,ANS;
int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n+2;i++){
        A1*=i;
    }
    for(int i = 1;i<=m;i++){
        A2*=i;
    }
    for(int i = 1;i<=n+3;i++){
        C1*=i;
    }
    for(int i = 1;i<=m;i++){
        C1/=i;
    }
    for(int i = 1;i<=n+3-m;i++){
        C1/=i;
    }
    A3=2;
    A4=A1/(n+2);
    for(int i = 1;i<=n+2;i++){
        C2*=i;
    }
    for(int i = 1;i<=m;i++){
        C2/=i;
    }
    for(int i = 1;i<=n+2-m;i++){
        C2/=i;
    }
    ANS=A1*A2*C1-A3*A4*A2*C2;
    cout<<ANS;
}