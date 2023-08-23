#include<iostream>
#include<algorithm>
using namespace std;
struct node{
    int a1,a2,val;
}gram[200005];
bool comp(node a,node b){
    return a.val<b.val;
}
int s[5005];
long long k=1,ans=0;
int find(int x){
    if(s[x]!=x) return s[x]=find(s[x]);
    else return x;
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;i++) s[i]=i;
    for(int i = 1;i<=m;i++) cin>>gram[i].a1>>gram[i].a2>>gram[i].val;
    sort(gram+1,gram+m+1,comp);
    ans=0;
    for(int i = 1;i<=m;i++){
        if(find(gram[i].a1)!=find(gram[i].a2)){
            s[find(gram[i].a1)]=find(gram[i].a2);
            k++,ans+=gram[i].val;
        }
    }
    if(k<n)cout<<"orz";
    else cout<<ans;
}