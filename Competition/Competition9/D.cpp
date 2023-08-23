#include<iostream>
#include<queue>
using namespace std;
int dt[1002][1002],zg[1002][1002];
int n,m;
int drx[9]={0,0,1,-1,1,1,-1,-1,0};
int dry[9]={1,-1,0,0,1,-1,1,1,0};
double m1,m2,h1,h2,a,s;
struct node{
    int x;
    int y;
    double s;
    double m;
    int step;
};
queue <node> Q;
void check(node x){
    cout<<x.step<<endl;
    if(h2+m2>=h1+x.m){
        cout<<"Oh f**k! ! !";
    }else if(h2+m2<h1+x.m){
        if(305.00<=h1+x.m){
            cout<<"jam! ! !";
        }
    }
}
void print1(){
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cout<<dt[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}
void print2(){
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cout<<zg[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}
int main(){
    cin>>h1>>m1>>s>>a>>h2>>m2;
    node now1;
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            char c;
            cin>>c;
            if(c=='#'){
                for(int w =0;w<=9;w++){
                    dt[i+dry[w]][j+drx[w]]=1;
                }
            }else if(c=='@') now1.y=i,now1.y=j;
            else if(c=='?') dt[i][j]=2;
        }
    }
    now1.s=s;
    now1.m=m1;
    now1.step=0;
    print1();
    print2();
    Q.push(now1);
    while(!Q.empty()){
        node now=Q.front();
        node next;
        Q.pop();
        zg[now.y][now.x]=1;
        if(dt[now.y][now.x]==2) check(now);
        for(int i = 0;i<=3;i++){
            if(now.y+dry[i]>0&&now.y+dry[i]<=n&&now.x+drx[i]>0&&now.x+drx[i]<=m&&dt[now.y+dry[i]][now.x+drx[i]]!=1&&zg[now.y][now.x]==0){
                next.y=now.y+dry[i];
                next.x=now.x+drx[i];
                next.s=0.99*now.s;
                next.m=0.98*now.m;
                next.step=now.step+1;
                Q.push(next);
            }
        }
    }
}