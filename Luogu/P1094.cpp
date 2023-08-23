#include<iostream>
//#include<cstdio>
#include<algorithm>
//#include<cstring>
//#include<string>
//#include<cstdin>
using namespace std;
int a[30002];
int main(){
    //freopen("P.in","r",stdin);
    //freopen("P.out","w",stdout);
    int w,n,ans = 0;
    cin>>w>>n;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int l = 1,r = n;
    while(l<r){
        if(a[l]+a[r]>=w){
            r--;
            ans++;
        }else{
            l++,r--;
            ans++;
        }
    }
    if(l==r) ans++;
    cout<<ans;
 	//fclose(stdin);
    //fclose(stdout);
    return 0;
} 