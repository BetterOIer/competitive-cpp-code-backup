#include<bits/stdc++.h>
using namespace std;
int d,k,n,ans=0,u,v;
map <int,int> m,s;
struct node{
    int data;
    int po;
};
queue <node> Q;
int midd(int L,int R){
    if(L==R) return L;
    int M=L+(R-L)/2;
    while(!Q.empty())Q.pop();
    s.clear();
    bool canfind=false;
    Q.push((node){0,0});
    while(!Q.empty()){
        node now=Q.front();
        Q.pop();
        if(now.data>=k){
            canfind=true;
            break;
        }
        for(int i = d-M;i<=d+M;i++){
            if(i>=1){
                auto n_p=m.find(now.po+i);
                if(n_p!= m.end()){
                    node next;
                    next.data=now.data+m[now.po+i];
                    next.po=now.po+i;
                    if(s.find(next.po)!=s.end()){
                        if(s[next.po]<next.data){
                            Q.push(next);
                        }
                    }else{
                        Q.push(next);
                    }
                }
            }
        }
    }
    if(canfind) return midd(L,M-1);
    else return midd(M+1,R);
}
int main(){
    cin>>n>>d>>k;
    for(int i = 1;i<=n;i++){
        cin>>u>>v;
        m[u]=v;
        if(v>0)ans+=v;
    }
    if(ans<k){
        cout<<-1;
        return 0;
    }
    int L=0,R=u-d;
    cout<<midd(L,R);
    return 0;
}