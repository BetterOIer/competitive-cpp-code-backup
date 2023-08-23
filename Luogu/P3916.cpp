#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector <int> P[100010];
queue <int> Q;
int ANS[100010],n,m,x,y;
int main(){
    cin>>n>>m;
    for(int i = 1;i<=m;i++){
        cin>>x>>y;
        P[y].push_back(x);
    }
    for(int i = n;i>=1;i--){
        if(!ANS[i]){
            Q.push(i);
        }
        while(!Q.empty()){
            int now=Q.front();
            Q.pop();
            ANS[now]=i;
            if(P[now].size()){
                for(int j = 0;j<=P[now].size()-1;j++){
                    if(!ANS[P[now][j]]) Q.push(P[now][j]);
                }
            }
        }
    }
    for(int i = 1;i<=n;i++){
        cout<<ANS[i]<<" ";
    }
}