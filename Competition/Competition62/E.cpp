#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
string s;
int d,t;
int main(){
    cin>>s;
    for(int i =0;i<=s.length()-1;i++){
        if(s[i]=='D'){
            d++;
        }else{
            t++;
        }
        if(t>=3){
            cout<<"T1"<<endl;
            break;
        }if(d>=3){
            cout<<"DRX"<<endl;
            break;
        }
    }
    return 0;
}