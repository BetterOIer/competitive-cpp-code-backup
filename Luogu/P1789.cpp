#include<iostream>
using namespace std;
int fk[105][105]={};
int main(){
    int n,m,k, x,y, sum=0;
    cin>>n>>m>>k;
    for(int i = 1;i<=m;++i){
        cin>>x>>y;
        fk[x+2][y+2+2]=1;
        fk[x+2][y]=1;
        fk[x][y+2]=1;
        fk[x+4][y+2]=1;
        for(int i = x+1;i<=x+3;++i){
            for(int w = y+1;w<=y+3;++w){
                fk[i][w]=1;
            }
        }
    }
    for(int i = 1;i<=k;++i){
        cin>>x>>y;
        for(int i = x;i<=x+4;++i){
            for(int w = y;w<=y+4;++w){
                fk[i][w]=1;
            }
        }
    }
    for(int i = 3;i<=n+2;++i){
        for(int w = 3;w<=n+2;++w){
            if(fk[i][w]==0){
                sum++;
            }
        }
    }
    cout<<sum;
    return 0;
} 