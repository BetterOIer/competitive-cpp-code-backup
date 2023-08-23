/*=================================================
* Le vent se lève, il faut tenter de vivre! 
* Author: Better_OIer Zyx
青春，其实在与现实的接受与妥协时就结束了​ --Naya
* Blog: betteroier.site:1000 
* FileStation: betteroier.site:1001
* OnlineJudge: betteroier.site:8888
=================================================*/
#include<iostream>
#include<deque>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int n;
int a[3000006],b[3000006];
deque<int>q;
int main(){
    n=read();
    for(int i = 1;i<=n;i++) a[i]=read();
    for(int i = 1;i<=n;i++){
        if(q.size()){
            while(q.size()&&a[q.back()]<a[i]){
                b[q.back()]=i;
                q.pop_back();
            }
        }
        q.push_back(i);
    }
    for(int i = 1;i<=n;i++)cout<<b[i]<<" ";
}