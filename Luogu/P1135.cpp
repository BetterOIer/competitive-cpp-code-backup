#include<iostream>
#include<queue>
//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//#include<string>
//#include<cstdin>
//#include<cmath>
//#include<stdlib>
using namespace std;
int a[10000],t[10000];
struct node{
    int floor,d;
};
queue <node> Q;
int main(){
    //freopen("P.in","r",stdin);
    //freopen("P.out","w",stdout);
    int n,A,B;
    cin>>n>>A>>B;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    Q.push((node){A,0});
    t[A] = 1;
    node now;
    while(!Q.empty()){
        now = Q.front();
        Q.pop();
        if(now.floor==B){
            break;
        }
        for(int i = -1;i<=1;i+=2){
            int dist = now.floor+a[now.floor]*i;
            if(dist>=1 &&dist<=n&&t[dist]==0){
                Q.push((node){dist,now.d+1});
                t[dist] = 1;
            }
        }
    }
    if(now.floor==B){
        cout<<now.d<<endl;
    }else {
        cout<<-1<<endl;
    }
 	//fclose(stdin);
    //fclose(stdout);
    return 0;
} 