#include<iostream>
#include<algorithm>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int n,maxy,maxx;
struct node{
    int y;
    int x;
};
node V[100005];
node LE[100005];
node V1[100005];
node LE1[100005];
int tot=0,tot1=0;
bool cmp(node a,node b){
    if(a.y==b.y) return a.x>b.x; 
    return a.y<b.y;
}
bool cmp1(node a,node b){
    if(a.x==b.x) return a.y>b.y; 
    return a.x<b.x;
}
bool cmp2(node a,node b){
    if(a.x==b.x) return a.y<b.y; 
    return a.x>b.x;
}
bool cmp3(node a,node b){
    if(a.y==b.y) return a.x<b.x; 
    return a.y>b.y;
}

int ifind(int y){
    int l=1,r=maxy;
    while (l < r){
        int mid =( l + r )>> 1;
        if (V[mid].y<=y) l = mid+1;
        else r=mid;
    }
    return l-1;
}
int ifind1(int x){
    int l=1,r=maxx;
    while (l < r){
        int mid =( l + r )>> 1;
        if (V1[mid].x<=x) l = mid+1;
        else r=mid;
    }
    return l-1;
}
int main(){
    int t=read(),ans=0;
    while(t--){
        tot=tot1=0;
        n=read();
        for(int i = 1;i<=n;i++){
            V1[i].y=V[i].y=read(),V1[i].x=V[i].x=read();
        }
        sort(V+1,V+n+1,cmp);
        sort(V1+1,V1+n+1,cmp1);
        maxy=V[n].y,maxx=V1[n].x;
        int half=n>>1;
        if(V[half+1].y>V[half].y||V1[half+1].x>V1[half].x){cout<<2<<endl;continue;}
        int left=half-ifind(V[half].y-1);
        for(int i = 1;i<=n;i++){
            if(V[i].y>=V[half].y){
                LE[++tot]=V[i];
            }
        }
        sort(LE+1,LE+tot+1,cmp2);
        if(LE[left].x>LE[left+1].x) ans=3;
        else ans=4;
        int left1=half-ifind1(V1[half].x-1);
        for(int i = 1;i<=n;i++){
            if(V1[i].x>=V1[half].x){
                LE1[++tot1]=V1[i];
            }
        }
        sort(LE1+1,LE1+tot1+1,cmp3);
        if(LE1[left1].y>LE1[left1+1].y) ans=min(3,ans);
        else ans=min(4,ans);
        cout<<ans<<endl;
    }
    return 0;
}