#include<iostream>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
const long long dx[]={-1,0,0,1},dy[]={0,-1,1,0};
map<long long,long long> m;
queue<long long> Q;
long long n;
int main(){
    cin>>n;
    Q.push(n);
    m[n]=0;
    while(Q.size()){
        int u=Q.front();Q.pop();
        int nowdt[3][3],f=0,g=0,n=u;
        if(u==123804765)break;
        for(int i=2;i>=0;i--)
            for(int j=2;j>=0;j--){
                nowdt[i][j]=n%10,n/=10;
                if(!nowdt[i][j])f=i,g=j;
            }
        for(int i=0;i<4;i++){
            int nx=f+dx[i],ny=g+dy[i],ns=0;
            if(nx<0||ny<0||nx>2||ny>2)continue;
            swap(nowdt[nx][ny],nowdt[f][g]);
            for(int i=0;i<3;i++) for(int j=0;j<3;j++)ns=(ns<<1)+(ns<<3)+nowdt[i][j];
            if(!m.count(ns)){
                m[ns]=m[u]+1;
                Q.push(ns);
            }
            swap(nowdt[nx][ny],nowdt[f][g]);
        }
    }
    cout<<m[123804765]<<endl;
    return 0;
}