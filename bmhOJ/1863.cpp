/*=================================================
* Le vent se lève, il faut tenter de vivre! 
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: betteroier.site:1000 
* FileStation: betteroier.site:1001
* OnlineJudge: betteroier.site:8888
=================================================*/
#include<iostream>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
string s;
int divid(int sta, int stb){
    long long ans=0;
    for(int i = sta;i<=stb;i++){
        if(isdigit(s[i])){
            ans=ans*10+(s[i]^48);
            if(ans>100000000LL){
                return -1;
            }
        }
    }
    return ans;
}
int main(){
    getline(cin,s);
    long long ans1=divid(0,s.find('+'));
    long long ans2=divid(s.find('+')+1,s.length()-1);
    if(ans1==-1||ans2==-1){
        cout<<"Large";
    }else{
        long long ans=ans1+ans2;
        if(ans>1e8)cout<<"Large";
        else cout<<ans;
    }
    return 0;
}
