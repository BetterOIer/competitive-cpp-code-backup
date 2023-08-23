#include<iostream>
#include<cstring>
#include<ctime>
using namespace std;
long long ans=0;
long long be[10];
long long af[10];
int main(){
    freopen("miracle.out","w",stdout);
    int ti=clock();
    for(long long i = 1000001;i<=10000000;i++){
        memset(be,0,sizeof be);
        memset(af,0,sizeof af);
        long long aft=i*2,bef=i;
        while(bef){
            be[bef%10]++;
            bef/=10;
        }
        while(aft){
            af[aft%10]++;
            aft/=10;
        }
        bool flag=true;
        for(int j = 0;j<=9;j++){
            if(be[j]!=af[j]){flag=false;break;}
        }
        if(flag)ans++,cout<<i<<", ";
    }
    /* for(long long i = 1;i<=1000000;i++){
        cout<<a[i]<<endl;;
    } */
    return 0;
}