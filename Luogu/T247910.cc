#include<iostream>
#include<string>
#include<queue>
using namespace std;
struct node{
    int F,L,R,C,len=1;
    long long AC[250]={1};
}a[110];
queue <int> Q;
long long res[1000];
int len=1;
void cheng(int x,int who,int child){
    for(int i = 0;i<a[who].len;i++){
        a[child].AC[i]=a[who].AC[i]*x;
    }
    while(a[child].AC[a[child].len-1]>9){
        a[child].AC[a[child].len]+=a[child].AC[a[child].len-1]/10;
        a[child].AC[a[child].len-1]%=10;
        a[child].len++;
    }
}
void add(int who){
    int LEN=max(len,a[who].len);
    for(int i = 0;i<LEN;i++){
        res[i]=res[i]+a[who].AC[i];
        if(res[i]>9){
            res[i+1]+=res[i]/10;
            res[i]%=10;
        }
    }
    len=LEN;
    while(res[len]>0){//?
        len++;
    }
    /* for(int i = len-1;i>=0;i--){
        cout<<res[i];
    }
    cout<<endl; */
}
int main(){
    int n,ro,f1,s1,f2,s2,root;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>ro>>f1>>s1>>f2>>s2;
        if(f1) a[ro].L=f1,a[f1].F=ro,a[f1].C=s1;
        if(f2) a[ro].R=f2,a[f2].F=ro,a[f2].C=s2;
    }
    for(int i = 1;i<=n;i++){
        if(a[i].F==0){
            root=i;
            break;
        }
    }
    Q.push(root);
    while(!Q.empty()){
        int now=Q.front();
        Q.pop();
        if(a[now].L){
            Q.push(a[now].L);
            cheng(a[a[now].L].C,now,a[now].L);
            add(a[now].L);
        }
        if(a[now].R){
            Q.push(a[now].R);
            cheng(a[a[now].R].C,now,a[now].R);
            add(a[now].R);
        }
    }
    for(int i = len-1;i>=0;i--){
        cout<<res[i];
    }
}