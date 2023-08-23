#include<iostream>
using namespace std;
int n,ans;
int ps[11];
int ps1[100000][11];
int flag=0;
void dfs(int step){
    if(ans>n)return;
    if(step==11){
        if(ans==n){
            flag++;
            for(int i = 1;i<=10;i++){
                ps1[flag][i]=ps[i];
            }
        }
        return ;
    }
    for(int i = 1;i<=3;i++){
        ans+=i;
        ps[step]=i;
        dfs(step+1);
        ps[step]=i;
        ans-=i;
    }
}
int main(){
    cin>>n;
    dfs(1);
    if(!flag)cout<<0;
    else{
        cout<<flag<<endl;
        for(int i = 1;i<=flag;i++){
            for(int j = 1;j<=10;j++){
                cout<<ps1[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}