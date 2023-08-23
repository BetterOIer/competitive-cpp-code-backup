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

int main(){
    freopen("in.in","w",stdout);
    srand((unsigned int )time(NULL));
    int t = rand()%10+1;
    cout<<t<<endl;
    while(t--){
        int n=rand()%400+1;cout<<n<<endl;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                cout<<rand()%2;
            }
            cout<<endl;
        }
    }
    return 0;
}