#include<iostream>
//#include<cstdio>
#include<algorithm>
//#include<cstring>
//#include<string>
//#include<cstdin>
#include<cmath>
//#include<stdlib>
#include<queue>
using namespace std;
struct panchangwei{
    double x;
    double y;
    double dis;
}Nbest[20];
double pcwcnl(int i){
    return sqrt(pow(Nbest[i].x-Nbest[i-1].x,2)+pow(Nbest[i].y-Nbest[i-1].y,2));
}
bool comp(panchangwei a,panchangwei b){
    return a.dis<b.dis;
}

int main(){
    freopen("P1433.in","r",stdin);
    //freopen("P.out","w",stdout);
    queue <panchangwei> Q;
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>Nbest[i].x>>Nbest[i].y;
    }
    Q.push(Nbest[0]);
    while(!Q.empty()){
        panchangwei chess = Q.front();
        Q.pop();
        for(int i = 1;i<=n;i++){
            if(Nbest[i].dis==0){
                Nbest[i].dis = pcwcnl(i)+chess.dis;
                 Q.push(Nbest[i]);
            }else if(Nbest[i].dis!=0){
                double k = sqrt(pow(Nbest[i].x-chess.x,2)+pow(Nbest[i].y-chess.y,2))+chess.dis;
                if(k<Nbest[i].dis){
                    Nbest[i].dis = k;
                    Q.push(Nbest[i]);
                }
            }
        }
    }
    sort(Nbest+1,Nbest+1+n,comp);
    cout<<Nbest[1].dis;
 	fclose(stdin);
    //fclose(stdout);
    return 0;
} 