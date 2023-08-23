#include<iostream>
using namespace std;
int n,k;
string s;
__uint128_t ANS=0;
inline void print(__uint128_t x){
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}
void dfs(int l,int nowk,__uint128_t nowans){
    if(nowk==0){
        __uint128_t e=0;
        for(int j = l;j<n;j++){
            e=e*10+s[j]-'0';
        }
        nowans*=e;
        ANS=max(ANS,nowans);
        return;
    }
    for(int i = l+1;i<=n-nowk;i++){
        __uint128_t e=0,o=nowans;
        for(int j = l;j<i;j++){
            e=e*10+s[j]-'0';
        }
        nowans*=e;
        dfs(i,nowk-1,nowans);
        nowans=o;
    }
}
int main(){
    cin>>n>>k>>s;
    dfs(0,k,1);
    print(ANS);
}