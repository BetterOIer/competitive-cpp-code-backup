#include<iostream>
using namespace std;
int a[10000005],k=0,n,opt;
void put(int x){
    a[++k]=x;
    int po=k;
    while(a[po]<a[po/2]){
        swap(a[po],a[po/2]);
        po/=2;
    }
}
void del(){
    int po=1,next;
    a[1]=a[k--];
    while(po*2<=k){
        next=po*2;
        if(next<k&&a[next+1]<a[next])next++;
        if(a[po]<=a[next])break;
        swap(a[po],a[next]);
        po=next;
    }
}
int main(){
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>opt;
        if(opt==1){
            int x;
            cin>>x;
            put(x);
        }else if(opt==2) cout<<a[1]<<endl;
        else del();
    }
}