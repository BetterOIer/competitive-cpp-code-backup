#include<iostream>
using namespace std;
int a[14][14],n,ans=0;
bool permit(int ro,int co){
    for(int i=1;i<=n;i++){
        if(a[ro][i]||a[i][co]){
            return 0;
        }
    }
    int i = ro,k1 = co,k2 = co;
    for(;i>=1&&k1>=1;i--,k1--){
        if(a[i][k1])return 0;
    }
    for(i = ro;i>=1&&k2<=n;i--,k2++){
        if(a[i][k2])return 0;
    }
    return 1;
}
void print(){
    for(int i = 1;i<=n;i++){
        for(int w = 1;w<=n;w++){
            if(a[i][w]){
                cout<<w<<" ";
            }
            //cout<<a[i][w]<<" ";
        }
        //cout<<endl;
    }
    cout<<endl;
}
void dfs(int ro){
    int co;
    if(ro == n+1){
        ans++;
        if(ans<=3){
            print();
        }
        return;
    }
    for(co = 1;co<=n;co++){
        if(permit(ro,co)){
            a[ro][co]=1;
            dfs(ro+1);
            a[ro][co]=0;
        }
    }
}
int main(){
    //freopen("P1219.in","r",stdin);
    //freopen("P1219.out","w",stdout);
    cin>>n;
    dfs(1);

    cout<<ans;
 	//fclose(stdin);
    //fclose(stdout);
    return 0;
} 