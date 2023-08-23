#include<iostream>
#define MAXN 121
using namespace std;
int dt[MAXN][MAXN],preadd[MAXN][MAXN],n,ans,ANS=0;
int main(){
    cin>>n;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            cin>>dt[i][j];
            preadd[i][j]=preadd[i-1][j]+preadd[i][j-1]-preadd[i-1][j-1]+dt[i][j];
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            for(int w = i;w<=n;w++){
                for(int k = j;k<=n;k++){
                    ans=preadd[w][k]-preadd[w][k-j]-preadd[w-i][k]+preadd[w-i][k-j];
                    ANS=max(ans,ANS);
                }
            }
        }
    }
    cout<<ANS;
}