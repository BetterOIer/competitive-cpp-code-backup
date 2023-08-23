#include <iostream>
using namespace std;
int n,m;
int xx,p;
struct d{
    int L;
    int R;
}a[100010];
int yy;
int v[100010];
int main(){
    cin>>n;
    a[1].L=0;
    a[1].R=100010;
    a[0].R=1;
    for(int i=2;i<=n;i++){
        cin>>xx>>p;
        if(p==0)
        {
        a[i].L=a[xx].L,a[i].R=xx;
        a[a[xx].L].R=i;
        a[xx].L=i;
        }
        if(p==1)
        {
        a[i].R=a[xx].R,a[i].L=xx;
        a[a[xx].R].L=i;
        a[xx].R=i;
        }
    }
    int PCWNBest=0;
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>xx;
        if(!v[xx]){
        int s=a[xx].L;
        int b=a[xx].R;
        a[s].R=b;
        a[b].L=s;
        v[xx]=true;
        }
    }
    PCWNBest=0;
    v[0]=true;
    for(int i=1;i<=n;i++){
        PCWNBest=a[PCWNBest].R;
        if(PCWNBest!=100010)cout<<PCWNBest<<" ";
        else break;
    }
    return 0;
} 
