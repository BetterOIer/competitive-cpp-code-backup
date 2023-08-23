#include<iostream>
//#include<cstdio>
#include<algorithm>
//#include<cstring>
//#include<string>
//#include<cstdin>
//#include<cmath>
using namespace std;
int a[305];
unsigned long long ans=0;
int main(){
    //freopen("P.in","r",stdin);
    //freopen("P.out","w",stdout);
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int l=0,r=n;
    bool flag = false;
    while(l<r){
        flag = !flag;
        ans+=(a[r]-a[l])*(a[r]-a[l]);
        if(flag)l++;
        else r--;
    }
    cout<<ans;
 	//fclose(stdin);
    //fclose(stdout);
    return 0;
} 