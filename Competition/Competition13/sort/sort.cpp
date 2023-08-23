#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    int num;
}yuan[8005];
int after[8005],n;
bool cmp(int a,int b){
    if(yuan[a].data==yuan[b].data) return a<b;
    return yuan[a].data<yuan[b].data;
}
int main(){
    freopen("sort2.in","r",stdin);
    freopen("sort.out","w",stdout);
    int q,opt,x,y;
    cin>>n>>q;
    for(int i = 1;i<=n;i++){
        cin>>yuan[i].data;
        yuan[i].num=i;
        after[i]=i;
    }
    sort(after+1,after+n+1,cmp);
    for(int i = 1;i<=n;i++){
        after[yuan[i].num]=i;
    }
    for(int i = 1;i<=q;i++){
        cin>>opt;
        if(opt==1){
            cin>>x>>y;
            if(yuan[after[x]].data>=y){
                yuan[x].data=y;
                for(int j=after[x]; j>1;--j){
                    if(yuan[j].data<yuan[j-1].data||yuan[j].data==yuan[j-1].data&&yuan[j-1].num){
                        swap(yuan[j],yuan[j-1]);
                        
                    }
                }
            }
            yuan[x]=y;
        }else{
            cin>>x;
           cout<<after[x]<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}