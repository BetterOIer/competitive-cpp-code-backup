#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
struct cyz{
    int hc;
    int fs;
}a[5001];
int comp(cyz a,cyz b){
    if(a.fs!=b.fs){
        return a.fs>b.fs;
    }else{
        return b.hc>a.hc;
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>a[i].hc>>a[i].fs;
    }
    m = floor(m*1.5);
    sort(a+1,a+n+1,comp);
    while(a[m].fs==a[m+1].fs){
        m++;
    }
    cout<<a[m].fs<<" "<<m;
    for(int i = 1;i<=m;i++){
        cout<<endl<<a[i].hc<<" "<<a[i].fs;
    }
    return 0;
} 