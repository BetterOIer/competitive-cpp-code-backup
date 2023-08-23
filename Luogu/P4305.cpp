#include<iostream>
#include<unordered_set>
using namespace std;
unordered_set <int> s;
inline int read()
{
	char c=getchar();int x=0,f=1;
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-48;
	return x*f;
}
int main(){
    int n=read(),k,l;
    for(int i = 1;i<=n;i++){
        s.clear();
        k=read();
        for(int i = 1;i<=k;i++){
            l=read();
            if(s.find(l)!=s.end())continue;
            s.insert(l);
            printf("%d ",l);
        }
        puts("");
    }
}