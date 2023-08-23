//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<queue>
#include<stack>
#include <cctype>
#include <cmath>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <list>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;
const int mod = 1e9+7;
const int MAXN = 1e5+5;
const int INF = 2147483647;
int F[2][MAXN][17];
int n,m,l,r;
void build(){
    int k = log2(n);
    for(int i = 1;i<=k;i++){
        for(int j = 1;j+(1<<i-1)<=n;j++){
            F[0][j][i]=max(F[0][j][i-1],F[0][j+(1<<i-1)][i-1]);
            F[1][j][i]=min(F[1][j][i-1],F[1][j+(1<<i-1)][i-1]);
        }
    }
}
void query(int l,int r){
    int d=log2(r-l+1);
    int Zmax,Zmin;
    Zmax=max(F[0][l][d],F[0][r-(1<<d)+1][d]);
    Zmin=min(F[1][l][d],F[1][r-(1<<d)+1][d]);
    cout<<Zmax-Zmin<<endl;
}
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++){
        scanf("%d", &F[0][i][0]);
        F[1][i][0]=F[0][i][0];
    }
    build();
    for(int i = 1;i<=m;i++){
        scanf("%d%d",&l,&r);
        query(l,r);
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
