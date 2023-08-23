#include<iostream>
#include<queue>
using namespace std;
struct node{
    int tr,fa,t;
};
struct cmp1{
    bool operator()(node x,node y){
        if(x.fa==y.fa) return x.t>y.t;
        return x.fa<y.fa;
    }
};
priority_queue<node,vector<node>,cmp1> Q;
int main(){
    int n,k,x;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        scanf("%d",&k);
        node now;
        now.t=i;
        now.tr=k;
        if(k<6){
            now.fa=min(k+3,k*k);
            if(now.fa<=8) Q.push(now);
        }
        else {
            if(k-3<=8) Q.push((node){k,k-3,i});
        }
    }
    scanf("%d",&x);
    while(--x) Q.pop();
    node now=Q.top();
    if(now.tr<=3)cout<<"sour -die";
    else if(now.tr>3&&now.tr<6) cout<<"too sour";
    else if(now.tr>=6&&now.tr<=8) cout<<"normal";
    else if(now.tr>8&&now.tr<=14) cout<<"diediedie";
    return 0;
}