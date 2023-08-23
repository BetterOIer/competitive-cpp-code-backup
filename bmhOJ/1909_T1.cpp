/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<deque>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n;
int h[25];
int nex[25];
deque<int>q_pre;
void ne(){
    for(int i =1;i<=(n<<1);i++){
        while(q_pre.size()&&h[q_pre.back()]<h[i]){
            nex[q_pre.back()]=i;
            q_pre.pop_back();
        }
        if(h[i]<h[i+1]){
            nex[i]=i+1;
        }else{
            q_pre.push_back(i);
        }
    }
    nex[q_pre.front()]=0;
    q_pre.pop_front();
    while(q_pre.size()){
        nex[q_pre.back()]=2147483647;
        q_pre.pop_back();
    }
}
int find(int from,int end){
    int he=h[from];
    int ans=1;
    for(int i = from+1;i<=end;i++){
        if(h[i]>=he){
            ans++;
            he=h[i];
        }
    }
    return ans;
}
int main(){
    n=read();
    for(int i = 1;i<=n;i++){
        h[i]=h[i+n]=read();
    }
    ne();
    long long ans=0;
    for(int i = 1;i<=n;i++){
        if(h[i]<h[i+1])ans++;
        else{
            if(nex[i]==0){
                ans+=find(i+1,i+n-1);
                --ans;
            }
            else ans+=find(i+1,min(nex[i],i+n-1));
        }
    }
    cout<<ans;
    return 0;
}
/* 
大佬，我认为你写的有问题，虽然我看不出哪里错了
hack数据：
10
0 7 10 8 2 6 4 1 6 12
正确输出：
18
 */