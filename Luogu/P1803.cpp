#include<iostream>
#include<algorithm>
using namespace std;
int ans = 0;
struct cptt{
    int L;
    int R;
}a[1000002];
bool comp(cptt x,cptt y){
    return x.R < y.R;
}
int main(){
    int n,end=0;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a[i].L>>a[i].R;
    }
    sort(a+1,a+n+1,comp);
    for(int i = 1;i<=n;i++){
        if(a[i].L>=end){
            ans++;
            end = a[i].R;
        }
    }
    cout<<ans;
    return 0;
} 