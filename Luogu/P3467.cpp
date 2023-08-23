#include<iostream>
#include<queue>
using namespace std;
struct node{
    int left;
    int right;
    int low;
};
queue <node> Q;
int hall[250005],n,cf[250005];
bool check(){
    bool sta=false,flag=false;
    int l,r,lo=1e9+5;
    for(int i = 1;i<=n+1;i++){
        hall[i]=hall[i-1]+cf[i];
        if(hall[i]&&sta==false){
            sta=true;
            flag=true;
            l=i;
        }
        else if(hall[i]==0&&sta==true){
            sta=false;
            r=i-1;
            Q.push((node){l,r,lo});
            lo=1e9+5;
        }
        if (sta==true) lo=lo>hall[i]? hall[i]:lo;
    }
    return flag;
}
int main(){
    int w,ans=0;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>w>>hall[i];
        cf[i]=hall[i]-hall[i-1];
    }
    cf[n+1]=hall[n+1]-hall[n];
    while(check()){
        while(!Q.empty()){
            node now=Q.front();Q.pop();
            cf[now.left]-=now.low;
            cf[now.right+1]+=now.low;
            ans++;
        }
    }
    cout<<ans;
}