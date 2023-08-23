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
int W,I,N,G,len;
string wstr[20],istr[20],nstr[20],gstr[20],name;
bool dp[205][205][5],can[205][205][5];
int ref(char _){if(_=='W') return 1; if(_=='I') return 2;if(_=='N') return 3; if(_=='G') return 4; return 0;}
int main(){
    W=read(),I=read(),N=read(),G=read();
    for(int i = 1;i<=W;i++){
        cin>>wstr[i];
        can[ref('W')][ref(wstr[i][0])][ref(wstr[i][1])]=true;
    }
    for(int i = 1;i<=I;i++){
        cin>>istr[i];
        can[ref('I')][ref(istr[i][0])][ref(istr[i][1])]=true;
    }
    for(int i = 1;i<=N;i++){
        cin>>nstr[i];
        can[ref('N')][ref(nstr[i][0])][ref(nstr[i][1])]=true;
    }
    for(int i = 1;i<=G;i++){
        cin>>gstr[i];
        can[ref('G')][ref(gstr[i][0])][ref(gstr[i][1])]=true;
    }
    cin>>name;
    len=name.length();
    for(int i = 1;i<=len;i++){
        dp[i][i][ref(name[i-1])]=true;
    }
    for(int le=1;le<len;le++){//le=length
        for(int l = 1;l<=len-le;l++){
            int r = l+le;
            for(int k = l;k<=r;k++){
                for(int z1=1;z1<=4;z1++){
                    for(int z2=1;z2<=4;z2++){
                        for(int z3=1;z3<=4;z3++){
                            if(can[z1][z2][z3]&&dp[l][k][z2]&&dp[k+1][r][z3])dp[l][r][z1]=true;
                        }
                    }
                }
            }
        }
    }
    bool f=false;
    if(dp[1][len][1]) {f=true;printf("W");}
    if(dp[1][len][2]) {f=true;printf("I");}
    if(dp[1][len][3]) {f=true;printf("N");}
    if(dp[1][len][4]) {f=true;printf("G");}
    if(!f) printf("The name is wrong!");
    return 0;
}