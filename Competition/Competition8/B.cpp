#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++){
        long long a,b,c,d,c1,c2,c3,c4,x_min,x_max;
        cin>>a>>b>>c>>d>>c1>>c2>>c3>>c4;
        x_min=max((long long)0,c-b);
        x_max=min(a,c);
        long long ans=a*c2+c*c3+b*c4-c*c4;
        if(c1-c2-c3+c4>=0){
            cout<<ans+x_min*(c1-c2-c3+c4)<<endl;
        }else{
            cout<<ans+x_max*(c1-c2-c3+c4)<<endl;
        }
    }
    return 0;
}