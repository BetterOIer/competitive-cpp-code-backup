#include<bits/stdc++.h>
#define N 400005
#define int long long
using namespace std;

inline int read(){
    int x=0,w=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return x*w;
}

string s[5]={"Oreo","ADmilk","Wangwangxb","Quduoduo","Wyyeggcookie"};

signed main(){
    srand((unsigned)time(NULL));
    cout<<s[rand()%5]<<endl;
    return 0;
}
