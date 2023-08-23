#include<iostream>
#include<algorithm>
using namespace std;
long long a[1000001];
bool comp(int a,int b){
    return a>b;
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,comp);
    int H = a[1],ans = 0;
    while(ans<m){
        for(int i = 1;a[i]==H;i++){
            --a[i];
            ++ans;
        }
        --H;
    }
    cout<<H;
    return 0;
} 