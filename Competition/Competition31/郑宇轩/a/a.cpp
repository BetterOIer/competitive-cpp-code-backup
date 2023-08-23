#include<iostream>
using namespace std;
long long ans=0;
int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int a,b,c;
    char opt;
    scanf("a+%d%c%d",&b,&opt,&c);
    if(opt=='>')ans=2147483647-c;
    else ans=2147483648+c;
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
}