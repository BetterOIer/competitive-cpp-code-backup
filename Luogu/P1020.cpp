#include <iostream>
#define max(a,b) (a>b?a:b)
using namespace std;
int a[50004],dp[50004],ANS=0,k=1,cnt;
int main(){
    while(scanf("%d",&a[k++])!=EOF);
    k-=2;
    cnt=1,dp[1]=a[1];
    for(int i=2;i<=k;i++)
    {
        if(dp[cnt]>=a[i])
            dp[++cnt]=a[i];
        else
            for(int j=1;1;j++)
            {
                if(dp[j]<a[i])
                {
                    dp[j]=a[i];
                    break;
                }
            }
    }
    cout<<cnt<<endl;
    /* for(int i = 1;i<=k;i++){
        dp[i]=1;
        for(int j=1;j<i;j++){
            if(a[j]>a[i]){
                dp[i]=max(dp[j]+1,dp[i]);
            }
        }
        ANS=max(ANS,dp[i]);
    }
    cout<<ANS<<endl; */
    ANS=1,dp[1]=a[1];
    for(int i=2;i<=k;i++)
    {
        if(dp[ANS]<a[i])
            dp[++ANS]=a[i];
        else
            for(int j=1;1;j++)
            {
                if(dp[j]>=a[i])
                {
                    dp[j]=a[i];
                    break;
                }
            }
    }
    printf("%d\n",ANS);
    return 0;
}