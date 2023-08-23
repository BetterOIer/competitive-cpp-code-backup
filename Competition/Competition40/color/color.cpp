#include<iostream>
#include<bitset>
#include<cstring>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
const int maxn=(1<<5)+1;
bitset<21>a;
int w[maxn],bpay[maxn];
int whi[25],tot=0;
bool usew[maxn];
long long ANS=9223372036854775807ll;
int main(){
    //freopen("color.in","r",stdin);
    //freopen("color.out","w",stdout);
    int n=read();
    int al=1<<n;
    for(int i = 0;i<al;i++) bpay[i]=read();
    for(int i = 0;i<al;i++) w[i]=read();
    while(a.to_ulong()<=al){
        bitset<21>b;
        b=a;
        tot=0;
        for(int i = 0;i<al;i++){
            usew[i]=false;
        }
        int tmpweishu=1;
        while(b.count()){
            if(b[0]) whi[++tot]=tmpweishu;
            b>>=1;
            tmpweishu++;
        }
        bitset<21>pai;
        int maxposs=1<<(tot-1);
        while(tot&&pai.to_ulong()<=maxposs){
            bitset<21>paicp;
            bitset<21>exa;
            paicp=pai;
            int cnt=1;
            if(!paicp.count())goto nex;
            while(paicp.count()){
                if(paicp[0]) exa[whi[cnt]-1]=1;
                paicp>>=1;
                cnt++;
            }
            usew[exa.to_ulong()]=true;
            nex:
            int to=pai.to_ulong()+1;
            bitset<21>paitmp(to);
            swap(paitmp,pai);
        }
        long long ans=0;
        for(int i = 0;i<al;i++){
            ans+=(int)usew[i]*bpay[i]+(int)!usew[i]*w[i];
        }
        if(ans<ANS)ANS=ans;
        int to=a.to_ulong()+1;
        bitset<21>atmp(to);
        swap(a,atmp);
    }
    cout<<ANS;
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}