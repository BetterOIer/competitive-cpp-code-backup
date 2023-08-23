#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int goods[2002];
bool choose[2002];
bool comp(int a, int b){return a>b;}
int main(){
    int n,r,R,L=0;
    cin>>n>>r;
    for(int i = 1;i<=n;i++){
        cin>>goods[i];
        R+=goods[i];
        L=L<goods[i]? goods[i]:L;
    }
    sort(goods+1,goods+n+1,comp);
    while(L<R){
        int M=(L+R)>>1,m,k=0,ans=0;
        memset(choose+1,0,sizeof(choose));
        while(k<n){
            m=M;
            for(int i = 1;i<=n;i++){
                if(m>=goods[i]&&choose[i]==false){
                    m-=goods[i];
                    choose[i]=true;
                    k++;
                }
            }
            ans++;
        }
        if(ans>r)L=M+1;
        else if(ans==r) R=M;
        else if(ans<r) R=M-1;
    }
    cout<<L;
}