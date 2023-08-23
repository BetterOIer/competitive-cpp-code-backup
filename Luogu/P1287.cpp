#include<iostream>
using namespace std;
long long solve(int n,int m){
    if(m<=0||n<m) return 0;
    if(n==m) return 1;
    return solve(n-1,m-1)+solve(n-1,m)*m;
}
long long fac(int n){
    if(n==1) return 1;
    return n*fac(n-1);
}
int main(){
    long long n,m;
    cin>>n>>m;
    cout<<solve(n,m)*fac(m);
}