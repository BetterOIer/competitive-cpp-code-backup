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
int n,m,len=25;
int a[600005],xor_sum[600005];
int root[600005],idx=0;
struct node{
    int ch[2];
    int ver[2]={-1,-1};
}tr[600000*20+5];
void insert(int pre, int &pos, int r,int val,int ver){
    pos=++idx;
    int c=(val>>r)&1;
    tr[pos].ch[!c]=tr[pre].ch[!c];
    tr[pos].ver[!c]=tr[pre].ver[!c];
    tr[pos].ver[c]=ver;
    //cout<<pos<<" "<<ver<<" "<<tr[pos].ver[!c]<<" "<<tr[pos].ver[c]<<endl;
    r? insert(tr[pre].ch[c],tr[pos].ch[c],r-1,val,ver):void();
}
int query(int pos,int lim,int r,int val){
     int c=(val>>r)&1;
     return (r? ((tr[pos].ver[!c]>=lim ? query(tr[pos].ch[!c],lim,r-1,val)+(1<<r):query(tr[pos].ch[c],lim,r-1,val))):(tr[pos].ver[!c]>=lim ? 1:0));
}
int main(){
    n=read(),m=read();
    insert(0,root[0],len,0,0);
    for(int i = 1;i<=n;i++){
        a[i]=read();xor_sum[i]=xor_sum[i-1]^a[i];
        insert(root[i-1],root[i],len,xor_sum[i],i);
    }
    for(int i = 1,x,l,r;i<=m;i++){
        char opt;
        cin>>opt;
        if(opt=='A'){
            ++n;
            a[n]=read();xor_sum[n]=xor_sum[n-1]^a[n];
            insert(root[n-1],root[n],len,xor_sum[n],n);
        }else{
            l=read(),r=read(),x=read();
            //cout<<tr[root[r-1]].ch[0]<<endl<<tr[root[r-1]].ch[1]<<endl<<tr[root[r-1]].ver[0]<<endl<<tr[root[r-1]].ver[1]<<endl<<endl;
            //cout<<"dzs: "<<(x^xor_sum[n])<<endl;
            cout<<(query(root[r-1],l-1,len,x^xor_sum[n]))<<endl;
        }
    }
    return 0;
}