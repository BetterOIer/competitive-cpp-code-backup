#include<iostream>
#include<algorithm>
using namespace std;
int a[51];
int main(){
    int n,l,r,ans=0;
    float tot=0;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        tot+=a[i];
    }
    tot = 1.0*tot/n;
    cin>>l>>r;
    if(tot<l||tot>r){
        cout<<-1;
        return 0;
    }
    int k = n;
    sort(a+1,a+n+1);
    for(int i = 1;i<=n&&a[i]<l;i++){
        if(a[k]-r>=l-a[i]){
            ans += l-a[i];
            a[k]-=l-a[i];
            a[i]= l;
        }else{
            ans +=a[k]-r;
            a[i]+=a[k]-r;
            a[k]=r;
            i--,k--;
        }
    }
    k=1;
    sort(a+1,a+n+1);
    for(int i = n;i>=1&&a[i]>r;i--){
        if(r-a[k]>=a[i]-r){
            ans+=a[i]-r;
            a[k]+=a[i]-r;
            a[i]= r;
        }else{
            ans+=r-a[k];
            a[i]-=r-a[k];
            a[k]=r;
            i--,k++;
        }
    }
    cout<<ans;
    return 0;
} 