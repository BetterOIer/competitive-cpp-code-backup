#include<iostream>
#include<algorithm>
using namespace std;
struct mine{
    int kg;
    float ave;
    int tot;
}a[101];
bool comp(mine a,mine b){
    return a.ave>b.ave;
}
int main(){
    int n,t,sum1=0;
    float sum2=0;
    cin>>n>>t;
    for(int i = 1;i<=n;i++){
        cin>>a[i].kg>>a[i].tot;
        sum1+=a[i].kg;
        sum2+=a[i].tot;
        a[i].ave = 1.0*a[i].tot/a[i].kg;
    }
    if(t>sum1){
        printf("%.2f",sum2);
        return 0;
    }
    sort(a+1,a+n+1,comp);
    int ans = 0;
    float sum = 0;
    while(t>0){
        ans++;
        if(t>=a[ans].kg){
            t-=a[ans].kg;
            sum+=a[ans].tot;
        }else{
            sum+=1.0*a[ans].tot*t/a[ans].kg;
            t=0;
        }
    }
    printf("%.2f",sum);
    return 0;
} 