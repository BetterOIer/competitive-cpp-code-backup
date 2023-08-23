/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<cstring>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int t,n;
string s;
int a[100005],idx=0,Idx;
int main(){
    t=read();
    while(t--){
        int ans=0,len=0,lenB=0;idx=Idx=0;
        bool flag=false;
        n=read();cin>>s;s="B"+s+"B";
        for(int i = 0;i<=n+1;i++){
            if(s[i]=='T'){
                if(lenB>=2){
                    flag=false;
                }lenB=0;
                len++;
            }else{
                lenB++;
                a[++idx]=len;
                if(i-len-4>=1&&flag==true){
                    a[idx]++;
                }
                if(len==2&&i-3!=0)flag=true;
                if(len>2)flag=false;
                len=0;
            }
        }flag=false;Idx=idx++;for(int i = n+1;i>=0;i--){
            if(s[i]=='T'){
                if(lenB>=2){
                    flag=false;
                }lenB=0;
                len++;
            }else{
                lenB++;
                if(i+4+len<=n&&flag==true){
                    a[idx]++;
                }
                idx--;
                if(len==2&&i+3!=n+1)flag=true;
                if(len>2)flag=false;
                len=0;
            }
        }
        for(int i = 0;i<=Idx;i++){
            ans=max(a[i],ans);
        }
        memset(a,0,sizeof a);
        cout<<ans<<endl;
    }
    return 0;
}