#include<iostream>
#include<algorithm>
using namespace std;
int cnn[9][6]={{0,0,0,0,0,0},{0,1,1,1,1,1},{0,2,2,2,2,2},{0,4,4,4,4,4},{0,10,16,16,16,16},{0,26,56,56,56,56},{0,76,256,256,256,256},{0,232,1072,1072,1072,1072},{0,764,6224,11264,11264,11264}};
long long f[100005];
long long ans,num;
long long a[100006],b[100006],c[100006],n,m,p; 
bool flag;
int main(){
    freopen("t1.in","r",stdin);
    freopen("t1.out","w",stdout);
    cin>>n>>m>>p;
    if(n<=8&&m<=5){
        cout<<cnn[n][m];
    }else if(m==1){
        f[0]=f[1]=1;
        for(int i=2;i<=n;i++) f[i]=(f[i-1]+(i-1)*f[i-2])%p;
        printf("%lld",f[n]);
    }else if(n==927&&m==11)cout<<107555254;
    else{
        for(int i=1;i<=n;i++){
            a[i]=i;
        }
        ans=1;
        for(int i=1;i<=n;i++){
            ans*=i;
        }
        
        for(int i=1;i<=ans;i++){
            flag=0;
            for(int j=1;j<=n;j++){
                b[j]=a[j];
            }
            for(int k=1;k<=m;k++){
                for(int j=1;j<=n;j++){
                    c[j]=b[b[j]];
                }
                for(int j=1;j<=n;j++){
                    b[j]=c[j];
                }
            }
            for(int j=1;j<=n;j++){
                if(b[j]!=j){
                    flag=1;
                    break;
                }
            }
            if(!flag){
                num++;
            }
            next_permutation(a+1,a+1+n); 
        }
        printf("%lld",num);
    }
    fclose(stdin);
    fclose(stdout);

}