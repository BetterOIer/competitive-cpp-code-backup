#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//#include<string>
//#include<cstdin>
//#include<cmath>
using namespace std;
int a[1000005];
int main(){
    //freopen("P.in","r",stdin);
    //freopen("P.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i = 1;i<=n;i++){
        int w;
        cin>>w;
        a[i] = a[i-1]+w;
    }
    int ans=0;
    for(int i = k+1;i<=n;i++){
        ans = ans>a[i]-a[i-k-1]? ans:a[i]-a[i-1-k];
    }
    cout<<ans;
 	//fclose(stdin);
    //fclose(stdout);
    return 0;
} 