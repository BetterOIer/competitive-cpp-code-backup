#include<iostream>
using namespace std;
inline int read(){
    char c=getchar();int x=0,f=1;
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
int main(){
    freopen("galaxy.in","r",stdin);
    freopen("galaxy.out","w",stdout);
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}