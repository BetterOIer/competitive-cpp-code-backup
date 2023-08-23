#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
vector <int> book[100010];
queue <int> Q;
struct node{
    int f,l;
}a[1000010];
bool seen[100010];
bool comp(node a,node b){
    if(a.f==b.f) return a.l<b.l;
    return a.f<b.f;
}
void dfs(int now){
    if(!seen[now]){
        cout<<now<<" ";
        seen[now]=true;
    }
    if(book[now].size()){
        for(int i = 0;i<=book[now].size()-1;i++){
            if(!seen[book[now][i]]) dfs(book[now][i]);
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=m;i++){
        cin>>a[i].f>>a[i].l;
    }
    sort(a+1,a+m+1,comp);
    for(int i = 1;i<=m;i++){
        book[a[i].f].push_back(a[i].l);
    }
    dfs(1);
    cout<<endl;
    memset(seen,false,sizeof(seen));
    Q.push(1);
    while(!Q.empty()){
        int now=Q.front();Q.pop();
        if(!seen[now]){
            cout<<now<<" ";
            seen[now]=true;
        }
        if(book[now].size()){
            for(int i = 0;i<=book[now].size()-1;i++){
                if(!seen[book[now][i]]) Q.push(book[now][i]);
            }
        }
    }
}