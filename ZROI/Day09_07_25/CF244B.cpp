/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
/* #include<iostream>

using namespace std;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long n;

long long dfs(long long last,bool lim,long long num1,long long num2){
    long long ans=0;
    if(!num1){
        for(long long i = lim;i<=9&&last*10+i<=n;i++){
            if(last*10+i>n){
                ans+=1;
                break;;
            }
            ans+=dfs(last*10+i,false,i,num2); 
        }
    }else if(!num2){
        for(long long i = 0;i<=9&&last*10+i<=n;i++){
            if(last*10+i>n){
                ans+=1;
                break;;
            }
            ans+=dfs(last*10+i,false,num1,i);
        }
    }else{
        if(last*10+num1<=n)ans+=dfs(last*10+num1,false,num1,num2);
        if(last*10+num2<=n)ans+=dfs(last*10+num2,false,num1,num2);
    }
    return ans;
}
long long main(){
    n=read();
    cout<<dfs(0,true,0,0);
    return 0;
} */

/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<set>
using namespace std;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long n;
set<long long>S;
void dfs(long long x,long long y,long long last){
    if(last>n)return;
    S.insert(last);
    if(last){
        dfs(x,y,(last<<3)+(last<<1)+x);
        dfs(x,y,(last<<3)+(last<<1)+y);
    }else{
        if(x)dfs(x,y,(last<<3)+(last<<1)+x);
        if(y)dfs(x,y,(last<<3)+(last<<1)+y);
    }
}
int main(){
    n=read();
    for(long long i = 0;i<=9;i++){
        for(long long j = 0;j<i;j++){
            dfs(i,j,0);
        }
    }
    cout<<S.size()-1;
    return 0;
}