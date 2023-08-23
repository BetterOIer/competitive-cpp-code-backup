#include<iostream>
#include<cstring>
using namespace std;
int b[1000010];
long long comp[50001],a[1000010];
unsigned long long ans=0;
int k=0;
int main(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    for(int i = 2;i<=n;i++){//长度
        for(int j = 1;j<=1+n-i;j++){//起始位置
            int flag=0,flag1=0;
            for(int w = j;w<=j+i-1;w++){
                if(b[w]&&b[w]<=j+i-1)flag1=1;
            }
            if(flag1)continue;
            for(int w = j;w<=j+i-1;w++){//位数比较
                for(int h = 1;h<=k;h++){
                    if(comp[h]==a[w]){
                        flag=1;
                        b[h]=w;
                        break;
                    }
                }
                if(!flag){
                    comp[++k]=a[w];
                }else{
                    break;
                }
            }
            if(!flag){
                ans++;
            }
            memset(comp,0,k+1);
            k=0;
        }
    }
    cout<<ans+n;
    return 0;
}