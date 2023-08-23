#include<bits/stdc++.h>
using namespace std;
int n;
bool a[28][1000005];
int str[1000005];
int vis[1005],cnt;
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n;getchar();
    for(int i=1;i<=n;i++){
        char f=getchar();
        vis[f-'A']=1;
        for(f=getchar();f>='A'&&f<='Z';f=getchar()){
            int x=f-'A';
            a[x][i]=1;
        }
    }

    for(int i=1;i<=n;i++){
        bool flag=1;
        for(int j=0;j<26;j++){
            int x=a[j][i];
            if(x==0)continue;
            if(!vis[j]){
                flag=0;
                break;
            }
        }
        if(flag==1){
            cout<<"Y";
            return 0;
        }
    }
    cout<<"N";

}