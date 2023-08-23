#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//#include<string>
//#include<cstdin>
//#include<cmath>
//#include<stdlib>
using namespace std;
int a[1000],ans=0,n;
void print(int x){
    cout<<a[1];
    for(int i = 2;i<=x-1;i++){
        cout<<"+"<<a[i];
    }
    cout<<endl;
}
void dfs(int x){
    if(ans==n){
        print(x);
        return;
    }
    for(int i = 1;i<n;i++){
        if(ans+i<=n&&i>=a[x-1]){
            ans+=i;
            a[x]=i;
            dfs(x+1);
            ans-=i;
            a[x]=0;
        }
    }
}
int main(){
    //freopen("P.in","r",stdin);
    //freopen("P.out","w",stdout);
    cin>>n;
    dfs(1);
 	//fclose(stdin);
    //fclose(stdout);
    return 0;
} 