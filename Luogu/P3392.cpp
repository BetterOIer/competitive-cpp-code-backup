#include<iostream>
using namespace std;
int ANS=INT32_MAX,ans,n,m;
char ma[51][51];
int check(int a,int b){
    ans=0;
    for(int i = 1;i<=a;i++){
        for(int w = 1;w<=m;w++){
            if(ma[i][w]!='W')ans++;
        }
    }
    for(int i = a+1;i<=a+b;i++){
        for(int w = 1;w<=m;w++){
            if(ma[i][w]!='B')ans++;
        }
    }
    for(int i = a+b+1;i<=n;i++){
        for(int w = 1;w<=m;w++){
            if(ma[i][w]!='R')ans++;
        }
    }
    return ans;
}
int main(){
    int l1,l2;
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        for(int w = 1;w<=m;w++){
            cin>>ma[i][w];
        }
    }
    for(l1=1;l1<=n-2;l1++){
        for(l2=1;l2<=n-l1-1;l2++){
            ans=check(l1,l2);
            ANS=min(ans,ANS);
        }
    }
    cout<<ANS;
}