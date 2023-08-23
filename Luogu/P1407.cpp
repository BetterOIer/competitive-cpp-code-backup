#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;
int dfn[40005],low[40005],scc[40005],cnt,n,m,tot,idx;
int instk[40005];
deque<int>stk;
map<string,int>M;
vector<int>ro[40005];
struct WF{
    int B;
    int G;
}wife[40005];
int REC(string s){
    if(M.find(s)==M.end()){
        M[s]=++idx;
        return idx;
    }
    return M[s];
}
void Tarjan(int pos){
    dfn[pos]=low[pos]=++tot;
    stk.push_front(pos);
    instk[pos]=true;
    for(int to:ro[pos]){
        if(!dfn[to]){
            Tarjan(to);
            low[pos]=min(low[pos],low[to]);
        }else if(instk[to]){
            low[pos]=min(low[pos],dfn[to]);
        }
    }
    if(dfn[pos]==low[pos]){
        int y;cnt++;
        do{
            y=stk.front();stk.pop_front();
            scc[y]=cnt;
            instk[y]=false;
        }while(y!=pos);
    }
}
int main(){
    cin>>n;
    string s1,s2;
    for(int i = 1;i<=n;i++){
        cin>>s1>>s2;
        wife[i].G=REC(s1),wife[i].B=REC(s2);
        ro[REC(s1)].push_back(REC(s2));
    }
    cin>>m;
    for(int i = 1;i<=m;i++){
        cin>>s1>>s2;
        ro[REC(s2)].push_back(REC(s1));
    }
    for(int i = 1;i<=idx;i++){
        if(dfn[i])continue;
        Tarjan(i);
    }
    for(int i = 1;i<=n;i++){
        if(scc[wife[i].B]==scc[wife[i].G]){
            cout<<"Unsafe\n";
        }else{
            cout<<"Safe\n";
        }
    }
    return 0;
}