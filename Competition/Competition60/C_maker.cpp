/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n[22];
int main(){
    srand((unsigned int)time(NULL));
    freopen("C.in","w",stdout);
    int t=rand()%20+1;
    t=20;
    cout<<t<<endl;
    int ans;
    do{
        ans=0;
        for(int i = 1,x;i<=t;i++){
            x=rand()%30000;
            n[i]=x;
            ans+=x;
        }
    }while(ans>100000);
    for(int i = 1;i<=t;i++){
        cout<<n[i]<<endl;
        for(int j = 1;j<=n[i];j++){
            cout<<rand()<<" ";
        }
        cout<<endl;
    }
    cout<<"\n\n\n\n\n"<<ans;;
    fclose(stdout);
    return 0;
}