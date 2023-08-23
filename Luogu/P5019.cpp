#include<iostream>
using namespace std;
int a[100002],ans = 0;
void cl(const int L,const int R){
    if(L-R>0){
        return;
    }
    int minn=INT32_MAX;
    int b[R-L+4]={},k=0;
    b[0]=L-1;
    for(int i = L;i<=R;i++){
        if(minn>a[i]){
            minn=a[i];
        }
    }
    ans+=minn;
    for(int i = L;i<=R;i++){
        a[i]-=minn;
        if(a[i]==0){
            b[++k]=i;
        }
    }
    b[++k] = R+1;
    for(int i = 0;i<=k;i++){
        cl(b[i]+1,b[i+1]-1);
    }
}
int main(){
    int n,minn=INT32_MAX;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    cl(1,n);
    cout<<ans;
    return 0;
} 