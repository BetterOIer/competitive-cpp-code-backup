#include<iostream>
#include<queue>
#include<ctime>
#include<cstdlib>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
struct node{
    int x;
    int y;
    bool operator < (const node &w)const{return w.y>y;}
};
int x,y;
priority_queue<node>Q,q;
int main(){
    srand((unsigned int)time(NULL));
    freopen("10.in","w",stdout);
    //freopen("1.out","w",stdout);
    int n=rand()%200000+1;
    cout<<n<<endl;
    for(int i = 1;i<=n;i++){
        x=rand(),y=rand();
        cout<<x<<" "<<y<<"\n";
        Q.push((node){x,y});
    }
    long long ans=0;
    while(Q.size()){
        ans++;
        node now=Q.top();
        Q.pop();
        int S=Q.size();
        for(int i = 1;i<=S;i++){
            node no=Q.top();Q.pop();
            if(abs(no.x-now.x)<=now.y-no.y) continue;
            q.push(no);
        }
        swap(Q,q);
    }
    fclose(stdout);
    freopen("10.out","w",stdout);
    cout<<ans;
    fclose(stdout);
}