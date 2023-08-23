#include<iostream>
#include<cmath>
using namespace std;
double num[300005];
int main(){
    freopen("seque.in","r",stdin);
    freopen("seque.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>num[i];
    }
    for(int i = 1,opt,x,y;i<=m;i++){
        cin>>opt>>x>>y;
        if(opt==1) for(int i = x;i<=y;i++) num[i]=cos(num[i]);
        else if(opt==2){
            double ans=0;
            for(int i = x;i<=y;i++) ans+=num[i];
            printf("%.15f\n",ans);
        }else{
            double z;
            cin>>z;
            for(int i = x;i<=y;i++)num[i]=z;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}