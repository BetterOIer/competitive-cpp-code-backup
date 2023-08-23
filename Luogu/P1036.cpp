#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//#include<string>
//#include<cstdin>
#include<cmath>
//#include<stdlib>
//#include<queue>
using namespace std;
int a[21][2],ans=0,n,k,answ=0,k1=0;
long long ans_list[200000];
int pdzs(int x){
    if(x==1||x==2){
        return 1;
    }
    int t = sqrt(x);
    for(int i = 2;i<=t;i++){
        if(x%i==0){
            return 0;
        }
    }
    return 1;
}
void dfs(int x){
    if(x>k){
        if(pdzs(ans)){
            answ++;
        }
        return;
    }
    for(int i = 1;i<=n;i++){
        if(a[i][1]==0&&ans_list[k1]<=a[i][0]){
            ans+=a[i][0];
            ans_list[++k1] = a[i][0];
            a[i][1]=1;
            dfs(x+1);
            ans-=a[i][0];
            ans_list[k1--] =0;
            a[i][1]=0;
        }
    }
}
int main(){
    //freopen("P.in","r",stdin);
    //freopen("P.out","w",stdout);
    cin>>n>>k;
    for(int i = 1;i<=n;i++){
        cin>>a[i][0];
    }
    dfs(1);
    cout<<answ/2;
 	//fclose(stdin);
    //fclose(stdout);
    return 0;
} 