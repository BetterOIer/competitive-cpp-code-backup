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
int n,a[300005];
int main(){
    n=read();
    for(int i = 0;i< n;i++) a[i]=read();
    int i = 0,j = 1,k = 0;
    while(i<n&&j<n&&k<n){
        if(a[(i+k)%n]==a[(j+k)%n])k++;
        else{
            a[(i+k)%n]>a[(j+k)%n]? i=i+k+1:j=j+k+1;
            if(i==j)i++;
            k=0;
        }
    }
    i = min(i,j);
    for(int cnt=1;cnt<=n;cnt++){
        cout<<a[i]<<" ";
        i=(i+1)%n;
    }
    return 0;
}