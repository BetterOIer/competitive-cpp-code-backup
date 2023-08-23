#include<iostream>
#include<cmath>
using namespace std;
int a[17],b[17],n;
bool hss(int x,int y){
    int k = x+y;
    int t = sqrt(k);
    if(k==1||k==2)return 1;
    for(int i = 2;i<=t;i++){
        if(k%i==0){
            return 0;
        }
    }
    return 1;
}
void dfs(int ans){
    if(ans==n){
        if(hss(a[ans],a[1])){
            for(int i = 1;i<=n;i++){
                if(i==n)cout<<a[i];
                else cout<<a[i]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    for(int i = 2;i<=n;i++){
        if(b[i]==0){
            if(hss(a[ans],i)){
                a[++ans]=i;
                b[i]=1;
                dfs(ans);
                a[ans--]=0;
                b[i]=0;
            }
        }
    }
    
}
int main(){
    freopen("UVA524.in","r",stdin);
    freopen("UVA524.out","w",stdout);
    a[1]=1;
    int t = 1;
    while(scanf("%d",&n) != EOF){
        if(t>=2)cout<<endl;
		printf("Case %d:\n",t);
        dfs(1);
        t++;
        
    }
 	fclose(stdin);
    fclose(stdout);
    return 0;
} 