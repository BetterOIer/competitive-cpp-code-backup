/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
const int mod = 1e9+7;
int n,k;
struct Matrix{
    int a[1001][1001];
    void init(){
        for(int i = 0;i<=k;i++){
            for(int j = 0;j<=k;j++){
                a[i][j]=0;
            }
        }
    }
    void output(){
        for(int i = 0;i<=k;i++){
            for(int j = 0;j<=k;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl<<endl;
    }
};
Matrix operator * (const Matrix &m1,const Matrix &m2){
    Matrix ans;
    ans.init();
    for(int o = 1;o<=k;o++){
        for(int i = 1;i<=k;i++){
            for(int j = 1;j<=k;j++){
                (ans.a[i][o]+=m1.a[i][j]*m2.a[j][o]%mod)%=mod;
            }
        }
    }
    return ans;
}
int main(){
    k=read(),n=read();
    Matrix base,ori;
    base.init(),ori.init();
    for(int i = 1;i<=k;i++) base.a[1][i]=ori.a[i][1]=1;
    for(int i = 2;i<=k;i++) base.a[i][i-1]=1;
    for(int i = 1;i<=n-k;i++) ori=base*ori;
    cout<<ori.a[1][1];
    return 0;
}