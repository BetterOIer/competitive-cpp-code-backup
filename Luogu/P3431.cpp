/*=================================================
* Le vent se lève, il faut tenter de vivre! 
* Author: Better_OIer Zyx
* 
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
int main(){
    int t=read();
    string s1,s2="314159265358979323846264338327";
    while(t--){
        cin>>s1;
        int ans=0;
        int len = s1.length();
        for(int i = 0;i<len;i++){
            if(s1[i]==s2[i])ans++;
        }
        cout<<ans<<endl;
    }
}