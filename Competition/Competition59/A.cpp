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
int main(){
    int t=read();
    while(t--){
        bool can=true;
        int n=read(),m=read(),k=read(),v_x=read(),v_y=read();
        for(int i = 1,x,y;i<=k;i++){
            x=read(),y=read();
            if(((v_x-x+v_y-y+1000000)&1)==0&&can){cout<<"NO"<<endl;can=false;}
        }
        if(can)cout<<"YES"<<endl;
    }
    return 0;
}