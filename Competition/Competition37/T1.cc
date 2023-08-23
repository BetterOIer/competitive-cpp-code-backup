#include<iostream>
#include<queue>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
deque<int>Q1;
int h[25];
int used[25];
int shortt[25];
long long ans=0,ans1=0;
int sum(int a,int b,int c){
    int anss=0;
    for(int i = a;i<=b;i++){
        anss+=min(used[i],c);
    }
    return anss;
}
int main(){
    int n=read(),x=read();
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
        while (Q1.size() && Q1.front() < i - x + 1) Q1.pop_front();
        while (Q1.size() && h[Q1.back()] > h[i]) Q1.pop_back();
        Q1.push_back(i);
        if (i >= x) shortt[i-x+1]=h[Q1.front()];
    }
    for(int i = 1;i<=n;i++){
        if(x*shortt[i]>sum(i,i+x-1,shortt[i])){
            for(int j = 0;j<x;j++){
                used[i]=max(used[i],shortt[i]);
            }
            ++ans;
        }
    }
    for(int i = 1;i<=n;i++){
        ans1+=used[i];
    }
    cout<<ans1<<endl<<ans<<endl;
}