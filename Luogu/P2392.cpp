#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int a[5][22],n[5];
bool comp(int a,int b){
    return a>b;
}
int main(){
    int ans=0;
    for(int i = 1;i<=4;i++){
        cin>>n[i];
    }
    for(int i = 1;i<=4;i++){
        for(int w = 1;w<=n[i];w++){
            cin>>a[i][w];
        }
        sort(a[i]+1,a[i]+n[i]+1,comp);
        for(int w = 1;w<=n[i];w++){
            ans+=a[i][w]==0||a[i][w+1]==0? max(a[i][w],a[i][w+1]):min(a[i][w],a[i][w+1]);
            a[i][w+1]=a[i][w]==0||a[i][w+1]==0? 0:abs(a[i][w]-a[i][w+1]);
            sort(a[i]+w+1,a[i]+n[i]+1,comp);
        }
    }
    cout<<ans;
    return 0;
} 