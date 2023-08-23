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
    string S1=R"(for(int i = 1;i<=n-)";
    string S2=R"(;i++){
            if(can)goto en;
            if((a[i+)";
    string S3=R"(]<<1)==a[i+)";
    string S4=R"(]+a[i]){
                can=true;
                goto en;
            }
        })";
    for(int i = 10000;i<=10100;i+=1){
        cout<<S1<<(i<<1)<<S2<<i<<S3<<(i<<1)<<S4<<endl;
    }
    return 0;
}