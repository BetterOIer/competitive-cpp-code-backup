#include<iostream>
#include<vector>
#include<queue>
#include <climits>
using namespace std;
vector <int> road[1505];
vector <int> cost[1505];
struct node{
    int po;
    long long ans;
};
queue <node> Q;
long long ANS=LLONG_MIN;
bool flag=false;
int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=m;i++){
        int u, v, w;
        cin>>u>>v>>w;
        road[u].push_back(v);
        cost[u].push_back(w);
    }
    Q.push((node){1,0});
    while(!Q.empty()){
        node now = Q.front();
        Q.pop();
        if(now.po==n){
            ANS=max(now.ans,ANS);
            flag=true;
        }
        for(int i = 0;i<road[now.po].size();i++){
            node next;
            next.po=road[now.po][i];
            next.ans=now.ans+cost[now.po][i];
            Q.push(next);
        }
    }
    if(flag) cout<<ANS;
    else cout<<-1;
}