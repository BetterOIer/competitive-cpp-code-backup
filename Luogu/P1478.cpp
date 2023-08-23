#include<iostream>
//#include<cstdio>
#include<algorithm>
//#include<cstring>
//#include<string>
//#include<cstdin>
using namespace std;
int c,d;
struct apple{
    int height;
    int strength;
    int act = 0;
}app[5001];
bool comp(apple a,apple b){
    return a.strength<b.strength;
}
int main(){
    //freopen("P.in","r",stdin);
    //freopen("P.out","w",stdout);
    int n,s;
    cin>>n>>s>>c>>d;
    for(int i = 1;i<=n;i++){
        cin>>app[i].height>>app[i].strength;
        if(app[i].height<=c+d){
            app[i].act = 1;
        }
    }
    sort(app+1,app+n+1,comp);
    int k = 1,ans = 0;;
    while(s>app[k].strength&&k<=n){
        if(app[k].act==1){
            ans++;
            s-=app[k++].strength;
        }else{
            k++;
        }
    }
    cout<<ans;
 	//fclose(stdin);
    //fclose(stdout);
    return 0;
} 