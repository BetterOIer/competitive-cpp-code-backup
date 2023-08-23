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
#include<algorithm>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
set<int>S;
string s,s1;
int t,n;
const int base = 19;
const int mod = 1e9+7;
int has(){
    long long ans=0;
    for(int i = 1;i<=n;i++){
        ans=((ans+1LL*(s1[i]-'0'))%mod)*base%mod;
    }
    return (ans%mod+mod)%mod;
}
int main(){
    while(cin>>t){
        for(int _ = 1;_<=t;_++){
            cin>>s;n=s.length();
            int k = 0, i = 0, j = 1;
            while (k < n && i < n && j < n) {
                if (s[(i + k) % n] == s[(j + k) % n]) {
                    k++;
                } else {
                    s[(i + k) % n] > s[(j + k) % n] ? i = i + k + 1 : j = j + k + 1;
                    if (i == j) i++;
                    k = 0;
                }
            }
            i = min(i, j);/* i=(i+1)%n; */
            s1=s.substr(i,n-i);
            string s2 = s.substr(0,i);/* reverse(s2.begin(),s2.end()); */
            s1+=s2;
            S.insert(has());
        }
        cout<<S.size()<<endl;
        S.clear();
    }
    return 0;
}