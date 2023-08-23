#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b;
int main(){
    cin>>a>>b;
    if(a>0&&b>0)cout<<a-b;
    else if(a<0&&b<0)cout<<a-b;
    else cout<<a+b;
}